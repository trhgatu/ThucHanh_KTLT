#include <stdio.h>

int main(){
    int a, b, c;
    printf("Nhap 3 so nguyen a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    int ketQua = c / (a - b);
    printf("Ket qua c/(a-b): %d", ketQua);
    return 0;
}