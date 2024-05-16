#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Ham kiem tra so nguyen to
bool SoNguyenTo(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Ham kiem tra so chinh phuong
bool SoChinhPhuong(int n)
{
    if (n < 0)
        return false;
    int canBacHai = (int)sqrt(n);
    return (canBacHai * canBacHai == n);
}

// Ham kiem tra so hoan hao
bool SoHoanHao(int n)
{
    if (n <= 1)
        return false;
    int tong = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i != n)
            {
                tong += i + n / i;
            }
            else
            {
                tong += i;
            }
        }
    }
    return (tong == n);
}

// Ham kiem tra so Fibonacci
bool SoFibonacci(int n)
{
    return SoChinhPhuong(5 * n * n + 4) || SoChinhPhuong(5 * n * n - 4);
}

int main()
{
    int luaChon, so;
    bool tiepTuc = true;

    while (tiepTuc)
    {
        printf("Chon mot chuc nang:\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Kiem tra so chinh phuong\n");
        printf("3. Kiem tra so hoan hao\n");
        printf("4. Kiem tra so Fibonacci\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon)
        {
        case 1:
            printf("Nhap mot so: ");
            scanf("%d", &so);
            if (SoNguyenTo(so))
            {
                printf("%d la so nguyen to.\n", so);
            }
            else
            {
                printf("%d khong phai la so nguyen to.\n", so);
            }
            break;
        case 2:
            printf("Nhap mot so: ");
            scanf("%d", &so);
            if (SoChinhPhuong(so))
            {
                printf("%d la so chinh phuong.\n", so);
            }
            else
            {
                printf("%d khong phai la so chinh phuong.\n", so);
            }
            break;
        case 3:
            printf("Nhap mot so: ");
            scanf("%d", &so);
            if (SoHoanHao(so))
            {
                printf("%d la so hoan hao.\n", so);
            }
            else
            {
                printf("%d khong phai la so hoan hao.\n", so);
            }
            break;
        case 4:
            printf("Nhap mot so: ");
            scanf("%d", &so);
            if (SoFibonacci(so))
            {
                printf("%d la so Fibonacci.\n", so);
            }
            else
            {
                printf("%d khong phai la so Fibonacci.\n", so);
            }
            break;
        case 0:
            tiepTuc = false;
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\n");
    }

    return 0;
}
