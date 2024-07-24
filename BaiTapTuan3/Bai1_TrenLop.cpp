#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DONG 100
#define MAX_COT 100

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

void tinhVaXuatTongDong(int a[][MAX_COT], int m, int n)
{
    int tong;
    printf("Tong gia tri tung dong cua ma tran:\n");
    for (int i = 0; i < m; i++)
    {
        tong = 0;
        for (int j = 0; j < n; j++)
        {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i + 1, tong);
    }
}

void xuatPhanTuLonNhatTrenMoiCot(int a[][MAX_COT], int m, int n)
{
    printf("Phan tu lon nhat tren moi cot:\n");
    for (int j = 0; j < n; j++)
    {
        int max = a[0][j];
        for (int i = 1; i < m; i++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
        printf("Cot %d: %d\n", j + 1, max);
    }
}
void xuatDuongBien(int a[][MAX_COT], int m, int n)
{
    printf("Cac phan tu thuoc cac duong bien tren, duoi, trai va phai cua ma tran:\n");
    for (int j = 0; j < n; j++)
    {
        printf("%5d", a[0][j]);
    }
    printf("\n");

    if (m > 1)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", a[m - 1][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < m - 1; i++)
    {
        printf("%5d", a[i][0]);
    }
    if (n > 1)
    {
        for (int i = 1; i < m - 1; i++)
        {
            printf("%5d", a[i][n - 1]);
        }
    }
    printf("\n");
}
int timMaxHang(int a[][MAX_COT], int dong, int cot) {
    int max = a[dong][0];
    for (int j = 1; j < cot; j++) {
        if (a[dong][j] > max) {
            max = a[dong][j];
        }
    }
    return max;
}
int timMinCot(int a[][MAX_COT], int dong, int cot, int cotHienTai) {
    int min = a[0][cotHienTai];
    for (int i = 1; i < dong; i++) {
        if (a[i][cotHienTai] < min) {
            min = a[i][cotHienTai];
        }
    }
    return min;
}
void xuatCacPhanTuCucDai(int a[][MAX_COT], int m, int n) {
    printf("Cac phan tu cuc dai:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int maxHang = timMaxHang(a, i, n);
            int minCot = timMinCot(a, m, n, j);
            if (a[i][j] == maxHang && a[i][j] == minCot) {
                printf("(%d, %d): %d\n", i + 1, j + 1, a[i][j]);
            }
        }
    }
}


void hienThiMenu()
{
    printf("\nMENU:\n");
    printf("1. Tao va xuat ma tran a chua cac phan tu ngau nhien\n");
    printf("2. Tinh va xuat tong gia tri tung dong cua ma tran\n");
    printf("3. Xuat phan tu lon nhat tren tung cot\n");
    printf("4. Xuat cac phan tu thuoc cac duong bien tren, duoi, trai, phai\n");
    printf("5. Xuat cac phan tu cuc dai\n");
    printf("5. Thoat\n");
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
            tinhVaXuatTongDong(maTran, m, n);
            break;
        case 3:
            xuatPhanTuLonNhatTrenMoiCot(maTran, m, n);
            break;
        case 4:
            xuatDuongBien(maTran, m, n);
            break;
        case 5:
            xuatCacPhanTuCucDai(maTran, m, n);
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 10);

    return 0;
}
