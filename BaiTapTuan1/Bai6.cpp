#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <setjmp.h>

jmp_buf env;

typedef struct {
    int ngay;
    int thang;
    int nam;
} NgaySinh;

typedef struct {
    char hoTen[100];
    NgaySinh ngaySinh;
    char gioiTinh[10];
} NguoiLaoDong;

int tinhTuoi(NgaySinh ns, int namHienTai) {
    return namHienTai - ns.nam;
}

void printError(int errorCode) {
    if (errorCode == 101) {
        printf("Tuoi khong thuoc trong tuoi lao dong (18-60/62 tuoi)\n");
    } else if (errorCode == 102) {
        printf("Gioi tinh khong hop le (khong phai nam/nu)\n");
    }
}

int main() {
    NguoiLaoDong nld;
    int namHienTai, tuoi, namNghiHuu;


    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    namHienTai = 1900 + ltm->tm_year;

    printf("Nhap ho ten: ");
    fgets(nld.hoTen, sizeof(nld.hoTen), stdin);
    nld.hoTen[strcspn(nld.hoTen, "\n")] = 0;

    printf("Nhap ngay sinh (ngay thang nam): ");
    scanf("%d %d %d", &nld.ngaySinh.ngay, &nld.ngaySinh.thang, &nld.ngaySinh.nam);

    printf("Nhap gioi tinh (nam/nu): ");
    scanf("%s", nld.gioiTinh);

    if (setjmp(env) == 0) {

        tuoi = tinhTuoi(nld.ngaySinh, namHienTai);

        if (tuoi < 18 || (strcmp(nld.gioiTinh, "nam") == 0 && tuoi > 62) || (strcmp(nld.gioiTinh, "nu") == 0 && tuoi > 60)) {
            longjmp(env, 101);
        }

        if (strcmp(nld.gioiTinh, "nam") != 0 && strcmp(nld.gioiTinh, "nu") != 0) {
            longjmp(env, 102);
        }

        if (strcmp(nld.gioiTinh, "nam") == 0) {
            namNghiHuu = nld.ngaySinh.nam + 62;
        } else {
            namNghiHuu = nld.ngaySinh.nam + 60;
        }

        printf("%s, gioi tinh %s, sinh ngay %02d/%02d/%04d. Hien tai (nam %d) %s da %d tuoi.\n",
               nld.hoTen, nld.gioiTinh, nld.ngaySinh.ngay, nld.ngaySinh.thang, nld.ngaySinh.nam, namHienTai, nld.hoTen, tuoi);
        printf("Thoi gian %s duoc nghi huu la thang %02d/%04d.\n", nld.hoTen, nld.ngaySinh.thang, namNghiHuu);
    } else {
        printError(setjmp(env));
    }

    return 0;
}
