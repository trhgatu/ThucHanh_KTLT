#include <stdio.h>

int sum_recursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum_recursive(n - 1);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n:");
    scanf("%d", &n);
    printf("Tong cua cac so tu 1 den %d theo phuong phep de quy: %d\n", n, sum_recursive(n));
    return 0;
}
