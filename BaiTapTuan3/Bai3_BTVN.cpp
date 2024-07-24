#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DONG 100
#define MAX_COT 100


int chuaChuSo2(int so) {
    while (so > 0) {
        if (so % 10 == 2) {
            return 1;
        }
        so /= 10;
    }
    return 0;
}
int demPhanTuChuaChuSo2(int a[][MAX_COT], int m, int n) {
    int dem = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chuaChuSo2(a[i][j])) {
                dem++;
            }
        }
    }

    return dem;
}
void taoVaXuatMaTran(int a[][MAX_COT], int m, int n, int k)
{
    srand(time(NULL));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % (k + 1);
        }
    }

    printf("Ma tran a [%d x %d] chua cac phan tu ngau nhien tu 0 den %d:\n", m, n, k);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}
void xuatCotSoLe(int a[][MAX_COT], int m, int n)
{
    printf("Cac cot chi chua so le:\n");
    for (int j = 0; j < n; j++)
    {
        int allOdd = 1;

        for (int i = 0; i < m; i++)
        {
            if (a[i][j] % 2 == 0)
            {
                allOdd = 0;
                break;
            }
        }

        if (allOdd)
        {
            printf("Cot %d:\n", j);
            for (int i = 0; i < m; i++)
            {
                printf("%5d", a[i][j]);
            }
            printf("\n");
        }
    }
}
int timMaxBien(int a[][MAX_COT], int m, int n)
{
    int max = a[0][0];
    for (int j = 0; j < n; j++)
    {
        if (a[0][j] > max)
        {
            max = a[0][j];
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (a[m - 1][j] > max)
        {
            max = a[m - 1][j];
        }
    }

    for (int i = 1; i < m - 1; i++)
    {
        if (a[i][0] > max)
        {
            max = a[i][0];
        }
    }

    for (int i = 1; i < m - 1; i++)
    {
        if (a[i][n - 1] > max)
        {
            max = a[i][n - 1];
        }
    }

    return max;
}
void xuatPhanTuCucTieu(int a[][MAX_COT], int m, int n) {
    printf("Cac phan tu cuc tieu trong ma tran:\n");


    printf("Cac phan tu cuc tiểu theo hàng:\n");
    for (int i = 0; i < m; i++) {
        int min = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        printf("Hang %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (a[i][j] == min) {
                printf("%5d", a[i][j]);
            }
        }
        printf("\n");
    }


    printf("Cac phan tu cuc tiểu theo cot:\n");
    for (int j = 0; j < n; j++) {
        int min = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
        printf("Cot %d:\n", j);
        for (int i = 0; i < m; i++) {
            if (a[i][j] == min) {
                printf("%5d", a[i][j]);
            }
        }
        printf("\n");
    }
}
void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void sapXepMaTran(int a[][MAX_COT], int m, int n) {
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            sapXepGiam(a[i], n);
        }
        else {
            sapXepTang(a[i], n);
        }
    }
}
void sapXepCotTang(int a[][MAX_COT], int m, int cot) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[i][cot] > a[j][cot]) {
                int temp = a[i][cot];
                a[i][cot] = a[j][cot];
                a[j][cot] = temp;
            }
        }
    }
}

void sapXepCotGiam(int a[][MAX_COT], int m, int cot) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[i][cot] < a[j][cot]) {
                int temp = a[i][cot];
                a[i][cot] = a[j][cot];
                a[j][cot] = temp;
            }
        }
    }
}


void sapXepMaTranTheoCot(int a[][MAX_COT], int m, int n) {
    for (int j = 0; j < n; j++) {
        if (j % 2 == 0) {
            sapXepCotTang(a, m, j);
        } else {
            sapXepCotGiam(a, m, j);
        }
    }
}

void hienThiMenu()
{
    printf("\nMENU:\n");
    printf("1. Tao va xuat ma tran a chua cac phan tu ngau nhien\n");
    printf("2. Xuat cac cot chi chua so le\n");
    printf("3. Tim phan tu lon nhat tren bien cua ma tran\n");
    printf("4. Dem so luong phan tu co chua chu so 2\n");
    printf("5. Xuat cac phan tu cuc tieu cua ma tran\n");
    printf("6. Sap xep ma tran: dong chan giam dan, dong le tang dan\n");
    printf("7. Sap xep ma tran: cot chan tang dan, cot le giam dan\n");
    printf("10. Thoat\n");
    printf("Nhap lua chon: ");
}

int main()
{
    int maTran[MAX_DONG][MAX_COT];
    int luaChon, m, n, k;

    printf("Nhap so dong m va so cot n cua ma tran: ");
    scanf("%d %d", &m, &n);

    printf("Nhap gia tri k (phan tu ngau nhien tu 0 den k): ");
    scanf("%d", &k);

    do
    {
        hienThiMenu();
        scanf("%d", &luaChon);

        switch (luaChon)
        {
        case 1:
            taoVaXuatMaTran(maTran, m, n, k);
            break;
        case 2:
            xuatCotSoLe(maTran, m, n);
            break;
        case 3:
            {
                int maxBien = timMaxBien(maTran, m, n);
                printf("Phan tu lon nhat tren bien cua ma tran: %d\n", maxBien);
            }
            break;
        case 4:
                {
                    int dem = demPhanTuChuaChuSo2(maTran, m, n);
                    printf("So luong phan tu co chua chu so 2: %d\n", dem);
                }
                break;
        case 5:
                xuatPhanTuCucTieu(maTran, m, n);
                break;
        case 6:
                sapXepMaTran(maTran, m, n);
                printf("Ma tran sau khi sap xep:\n");
                taoVaXuatMaTran(maTran, m, n, k);
                break;

        case 7:
                sapXepMaTranTheoCot(maTran, m, n);
                printf("Ma tran sau khi sap xep theo yeu cau:\n");
                taoVaXuatMaTran(maTran, m, n, k);
                break;
        case 10:
                printf("Thoat chuong trinh.\n");
                break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 10);

    return 0;
}
