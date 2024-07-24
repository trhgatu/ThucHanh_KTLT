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


void hienThiMenu()
{
    printf("\nMENU:\n");
    printf("1. Tao va xuat ma tran a chua cac phan tu ngau nhien\n");
    printf("2. Xuat cac cot chi chua so le\n");
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
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 10);

    return 0;
}
