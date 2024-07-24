#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void hienThiMenu() {
    printf("\nMENU:\n");
    printf("1. Tao va xuat ma tran a chua cac phan tu ngau nhien\n");
    printf("2. Xuat cac phan tu tren duong cheo chinh\n");
    printf("3. Xuat cac phan tu tren duong cheo song song voi duong cheo chinh\n");
    printf("3. Thoat\n");
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
                printf("Thoat chuong trinh.\n");
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
