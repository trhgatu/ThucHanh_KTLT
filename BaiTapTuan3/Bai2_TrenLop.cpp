#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
void taoMaTran(int n, int **a) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
        }
    }
}

void xuatMaTran(int n, int **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void xuatDuongCheoChinh(int n, int **a) {
    printf("Cac phan tu tren duong cheo chinh:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
}
void xuatDuongCheoSongSong(int n, int **a) {
    printf("Cac phan tu tren duong cheo song song voi duong cheo chinh:\n");

    for (int k = 1; k < n; k++) {
        printf("Duong cheo song song voi duong cheo chinh (k = %d):\n", k);
        for (int i = 0; i < n - k; i++) {
            printf("%d ", a[i][i + k]);
        }
        printf("\n");
    }

    for (int k = 1; k < n; k++) {
        printf("Duong cheo song song voi duong cheo chinh (k = -%d):\n", k);
        for (int i = k; i < n; i++) {
            printf("%d ", a[i][i - k]);
        }
        printf("\n");
    }
}
int timMaxTamGiacTren(int n, int **a) {
    int max = a[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }

    return max;
}

void sapXepMaTranZicZac(int n, int **a) {
    int *temp = (int *)malloc(n * n * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[index++] = a[i][j];
        }
    }

    std::sort(temp, temp + n * n);


    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                a[i][j] = temp[index++];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
        }
    }

    free(temp);
}
void sapXepDuongCheoChinh(int n, int **a) {
    int *duongCheoChinh = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        duongCheoChinh[i] = a[i][i];
    }
    std::sort(duongCheoChinh, duongCheoChinh + n);
    for (int i = 0; i < n; i++) {
        a[i][i] = duongCheoChinh[i];
    }

    free(duongCheoChinh);
}
void hienThiMenu() {
    printf("\nMENU:\n");
    printf("1. Tao va xuat ma tran a chua cac phan tu ngau nhien\n");
    printf("2. Xuat cac phan tu tren duong cheo chinh\n");
    printf("3. Xuat cac phan tu tren duong cheo song song voi duong cheo chinh\n");
    printf("4. Tim phan tu max thuoc tam giac tren duong cheo chinh\n");
    printf("5. Sap xep ma tran theo kieu zic-zac\n");
    printf("6. Sap xep duong cheo chinh\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int n;

    do {
        printf("Nhap cap cua ma tran (n >= 5): ");
        scanf("%d", &n);
    } while (n < 5);


    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    int choice;

    do {
        hienThiMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                taoMaTran(n, a);
                printf("Ma tran vua tao:\n");
                xuatMaTran(n, a);
                break;
            case 2:
                xuatDuongCheoChinh(n, a);
                break;
            case 3:
                xuatDuongCheoSongSong(n, a);
                break;
            case 4:
                {
                    int max = timMaxTamGiacTren(n, a);
                    printf("Phan tu max thuoc tam giac tren duong cheo chinh: %d\n", max);
                }
                break;
            case 5:
                sapXepMaTranZicZac(n, a);
                printf("Ma tran sau khi sap xep zic-zac:\n");
                xuatMaTran(n, a);
                break;
            case 6:
            sapXepDuongCheoChinh(n, a);
                printf("Ma tran sau khi sap xep duong cheo chinh:\n");
                xuatMaTran(n, a);
                break;
            case 7:
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (choice != 3);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
