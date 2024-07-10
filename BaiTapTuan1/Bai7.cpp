#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void nhapM1C_SoNguyen(int **a, int *n) {
    *n = 10;
    *a = (int *)malloc(*n * sizeof(int));
    for(int i = 0; i < *n; i++) {
        *(*a + i) = rand() % 100;
    }
}

void xuatM1C_SoNguyen(int *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, *(a + i), (void*)(a + i));
        printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %p", i, a[i], (void*)(a + i));
    }
}

// a. Tìm phần tử lớn nhất của a, xuất ra phần tử lớn nhất và địa chỉ của nó thông qua con trỏ mảng.
void timPhanTuLonNhat(int *a, int n) {
    int max = a[0];
    int *diaChiMax = a;

    for(int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
            diaChiMax = a + i;
        }
    }

    printf("\nPhan tu lon nhat: %d, dia chi: %p\n", max, (void*)diaChiMax);
}

// b. Xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất
void timChanLe(int *a, int n) {
    int chanMax = -1, leMin = -1;
    int *diaChiChanMax = NULL, *diaChiLeMin = NULL;

    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            if(diaChiChanMax == NULL || a[i] > chanMax) {
                chanMax = a[i];
                diaChiChanMax = a + i;
            }
        } else {
            if(diaChiLeMin == NULL || a[i] < leMin) {
                leMin = a[i];
                diaChiLeMin = a + i;
            }
        }
    }

    if(diaChiChanMax != NULL) {
        printf("\nPhan tu chan lon nhat: %d, dia chi: %p\n", chanMax, (void*)diaChiChanMax);
    } else {
        printf("\nKhong co phan tu chan trong mang\n");
    }

    if(diaChiLeMin != NULL) {
        printf("\nPhan tu le nho nhat: %d, dia chi: %p\n", leMin, (void*)diaChiLeMin);
    } else {
        printf("\nKhong co phan tu le trong mang\n");
    }
}

// c. Xóa phần tử có giá trị 0
void xoaPhanTuZero(int **a, int *n) {
    int count = 0;
    int *temp = (int *)malloc(*n * sizeof(int));

    for(int i = 0; i < *n; i++) {
        if((*a)[i] != 0) {
            temp[count++] = (*a)[i];
        }
    }

    free(*a);
    *a = temp;
    *n = count;
}

// d. Thêm phần tử x vào sau phần tử đầu tiên
void themPhanTuSauDauTien(int **a, int *n, int x) {
    *a = (int *)realloc(*a, (*n + 1) * sizeof(int));

    for(int i = *n; i > 1; i--) {
        (*a)[i] = (*a)[i - 1];
    }

    (*a)[1] = x;
    (*n)++;
}

// Hàm kiểm tra số chính phương
int laSoChinhPhuong(int x) {
    int sqr = (int)sqrt(x);
    return (sqr * sqr == x);
}

// e. Tính tổng các phần tử là số chính phương
void tongSoChinhPhuong(int *a, int n) {
    int tong = 0;

    for(int i = 0; i < n; i++) {
        if(laSoChinhPhuong(a[i])) {
            tong += a[i];
        }
    }

    printf("\nTong cac phan tu la so chinh phuong: %d\n", tong);
}

// f. Xuất các số cực đại trong a
void xuatSoCucDai(int *a, int n) {
    printf("\nCac so cuc dai trong mang: ");

    if(n > 1 && a[0] > a[1]) {
        printf("%d ", a[0]);
    }

    for(int i = 1; i < n - 1; i++) {
        if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
            printf("%d ", a[i]);
        }
    }

    if(n > 1 && a[n - 1] > a[n - 2]) {
        printf("%d ", a[n - 1]);
    }

    printf("\n");
}

int main() {
    srand(time(0));

    int *a;
    int n;

    nhapM1C_SoNguyen(&a, &n);
    xuatM1C_SoNguyen(a, n);

    timPhanTuLonNhat(a, n);
    timChanLe(a, n);
    xoaPhanTuZero(&a, &n);
    printf("\nMang sau khi xoa phan tu co gia tri 0:\n");
    xuatM1C_SoNguyen(a, n);

    int x;
    printf("\nNhap gia tri phan tu can them: ");
    scanf("%d", &x);
    themPhanTuSauDauTien(&a, &n, x);
    printf("\nMang sau khi them phan tu:\n");
    xuatM1C_SoNguyen(a, n);

    tongSoChinhPhuong(a, n);
    xuatSoCucDai(a, n);

    free(a);

    return 0;
}
