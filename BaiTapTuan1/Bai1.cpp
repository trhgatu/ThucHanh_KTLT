#include <stdio.h>
#include <conio.h>

int main()
{
    int a = 0, b = 0;
    printf("Nhap a va b");
    scanf("%d%d", &a, &b);

    try
    {
        if (b == 0)
        {
            throw "So chia khong duoc la 0";
        }
        else
        {
            int t = a / b;
        }
    }
    catch (const char *st)
    {
        printf("Loi: %s", st);
    }
    return 0;
}
