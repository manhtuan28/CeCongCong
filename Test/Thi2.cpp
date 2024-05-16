#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

void nhapMang(int arr[], int *n);
void hienThiMang(int arr[], int n);
int tinhTongChan(int arr[], int n);
float tinhTrungBinhDuong(int arr[], int n);
void sapXepTangDan(int arr[], int n);
void sapXepGiamDan(int arr[], int n);
void sapXepAm0Duong(int arr[], int n);
void sapXepNguyenToDau(int arr[], int n);
void sapXepChanTruocLeSau(int arr[], int n);
int timMax(int arr[], int n);
int timMin(int arr[], int n);
bool timXiBangXjCongXk(int arr[], int n);
int demPhanTuX(int arr[], int n, int x, int viTri[]);
bool timSoNguyenTo(int arr[], int n, int viTri[], int *soLuong);
bool timSoChinhPhuong(int arr[], int n, int viTri[], int *soLuong);
void chenPhanTu(int arr[], int *n, int x, int k);
void xoaPhanTu(int arr[], int *n, int k);
void xoaPhanTuGiaTri(int arr[], int *n, int giaTri);

bool laSoNguyenTo(int n);
bool laSoChinhPhuong(int n);
void hoanDoi(int *a, int *b);

// Nhập vào dãy số, hiển thị dãy số đã nhập
void nhapMang(int arr[], int *n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Các hàm tính toán cơ bản
int tinhTongChan(int arr[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            tong += arr[i];
        }
    }
    return tong;
}

float tinhTrungBinhDuong(int arr[], int n)
{
    int tong = 0;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            tong += arr[i];
            dem++;
        }
    }
    return dem == 0 ? 0 : (float)tong / dem;
}

// Hàm sắp xếp
void sapXepTangDan(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                hoanDoi(&arr[i], &arr[j]);
            }
        }
    }
}

void sapXepGiamDan(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                hoanDoi(&arr[i], &arr[j]);
            }
        }
    }
}

void sapXepAm0Duong(int arr[], int n)
{
    int temp[MAX_SIZE];
    int index = 0;

    // Các số âm
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp[index++] = arr[i];
        }
    }
    // Các số 0
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            temp[index++] = arr[i];
        }
    }
    // Các số dương
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void sapXepNguyenToDau(int arr[], int n)
{
    int temp[MAX_SIZE];
    int index = 0;

    // Các số nguyên tố
    for (int i = 0; i < n; i++)
    {
        if (laSoNguyenTo(arr[i]))
        {
            temp[index++] = arr[i];
        }
    }
    // Các số không phải nguyên tố
    for (int i = 0; i < n; i++)
    {
        if (!laSoNguyenTo(arr[i]))
        {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void sapXepChanTruocLeSau(int arr[], int n)
{
    int temp[MAX_SIZE];
    int index = 0;

    // Các số chẵn
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            temp[index++] = arr[i];
        }
    }
    // Các số lẻ
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

// Giá trị lớn nhất (nhỏ nhất) của dãy số
int timMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int timMin(int arr[], int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

// Tìm kiếm phần tử xi sao cho tồn tại cặp xj, xk thỏa mãn xi = xj + xk
bool timXiBangXjCongXk(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && i != k && j != k && arr[i] == arr[j] + arr[k])
                {
                    printf("Tim thay xi = xj + xk voi xi = %d, xj = %d, xk = %d\n", arr[i], arr[j], arr[k]);
                    return true;
                }
            }
        }
    }
    return false;
}

// Đếm phần tử x trong dãy
int demPhanTuX(int arr[], int n, int x, int viTri[])
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            viTri[dem++] = i;
        }
    }
    return dem;
}

// Tìm số nguyên tố trong dãy
bool timSoNguyenTo(int arr[], int n, int viTri[], int *soLuong)
{
    *soLuong = 0;
    for (int i = 0; i < n; i++)
    {
        if (laSoNguyenTo(arr[i]))
        {
            viTri[(*soLuong)++] = i;
        }
    }
    return (*soLuong > 0);
}

// Tìm số chính phương trong dãy
bool timSoChinhPhuong(int arr[], int n, int viTri[], int *soLuong)
{
    *soLuong = 0;
    for (int i = 0; i < n; i++)
    {
        if (laSoChinhPhuong(arr[i]))
        {
            viTri[(*soLuong)++] = i;
        }
    }
    return (*soLuong > 0);
}

// Chèn phần tử vào vị trí k
void chenPhanTu(int arr[], int *n, int x, int k)
{
    if (k >= 0 && k <= *n)
    {
        for (int i = *n; i > k; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[k] = x;
        (*n)++;
    }
    else
    {
        printf("Vi tri chen khong hop le.\n");
    }
}

// Xóa phần tử ở vị trí k
void xoaPhanTu(int arr[], int *n, int k)
{
    if (k >= 0 && k < *n)
    {
        for (int i = k; i < *n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    }
    else
    {
        printf("Vi tri xoa khong hop le.\n");
    }
}

// Xóa các phần tử có giá trị giaTri
void xoaPhanTuGiaTri(int arr[], int *n, int giaTri)
{
    int i = 0;
    while (i < *n)
    {
        if (arr[i] == giaTri)
        {
            xoaPhanTu(arr, n, i);
        }
        else
        {
            i++;
        }
    }
}

// Các hàm hỗ trợ
bool laSoNguyenTo(int n)
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

bool laSoChinhPhuong(int n)
{
    if (n < 0)
        return false;
    int canBacHai = (int)sqrt(n);
    return (canBacHai * canBacHai == n);
}

void hoanDoi(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[MAX_SIZE];
    int n, x, k;
    int viTri[MAX_SIZE], soLuong;
    bool tiepTuc = true;

    while (tiepTuc)
    {
        int luaChon;
        printf("Chon mot chuc nang:\n");
        printf("1. Nhap vao day so\n");
        printf("2. Hien thi day so\n");
        printf("3. Tinh tong cac so chan\n");
        printf("4. Tinh trung binh cong cac so duong\n");
        printf("5. Sap xep day so tang dan\n");
        printf("6. Sap xep day so giam dan\n");
        printf("7. Sap xep cac so am, 0 va duong\n");
        printf("8. Sap xep cac so nguyen to ve dau\n");
        printf("9. Sap xep so chan truoc, so le sau\n");
        printf("10. Tim gia tri lon nhat\n");
        printf("11. Tim gia tri nho nhat\n");
        printf("12. Tim phan tu xi = xj + xk\n");
        printf("13. Dem so lan xuat hien cua phan tu x\n");
        printf("14. Tim so nguyen to trong day\n");
        printf("15. Tim so chinh phuong trong day\n");
        printf("16. Chen phan tu vao vi tri k\n");
        printf("17. Xoa phan tu o vi tri k\n");
        printf("18. Xoa phan tu co gia tri 0\n");
        printf("19. Xoa phan tu co gia tri le\n");
        printf("20. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon)
        {
        case 1:
            nhapMang(arr, &n);
            break;
        case 2:
            hienThiMang(arr, n);
            break;
        case 3:
            printf("Tong cac so chan: %d\n", tinhTongChan(arr, n));
            break;
        case 4:
            printf("Trung binh cong cac so duong: %.2f\n", tinhTrungBinhDuong(arr, n));
            break;
        case 5:
            sapXepTangDan(arr, n);
            printf("Day so sau khi sap xep tang dan: ");
            hienThiMang(arr, n);
            break;
        case 6:
            sapXepGiamDan(arr, n);
            printf("Day so sau khi sap xep giam dan: ");
            hienThiMang(arr, n);
            break;
        case 7:
            sapXepAm0Duong(arr, n);
            printf("Day so sau khi sap xep am, 0, duong: ");
            hienThiMang(arr, n);
            break;
        case 8:
            sapXepNguyenToDau(arr, n);
            printf("Day so sau khi sap xep so nguyen to ve dau: ");
            hienThiMang(arr, n);
            break;
        case 9:
            sapXepChanTruocLeSau(arr, n);
            printf("Day so sau khi sap xep so chan truoc, so le sau: ");
            hienThiMang(arr, n);
            break;
        case 10:
            printf("Gia tri lon nhat: %d\n", timMax(arr, n));
            break;
        case 11:
            printf("Gia tri nho nhat: %d\n", timMin(arr, n));
            break;
        case 12:
            if (!timXiBangXjCongXk(arr, n))
            {
                printf("Khong tim thay xi thoa man xi = xj + xk\n");
            }
            break;
        case 13:
            printf("Nhap gia tri x: ");
            scanf("%d", &x);
            soLuong = demPhanTuX(arr, n, x, viTri);
            printf("Gia tri %d xuat hien %d lan tai cac vi tri: ", x, soLuong);
            for (int i = 0; i < soLuong; i++)
            {
                printf("%d ", viTri[i]);
            }
            printf("\n");
            break;
        case 14:
            if (timSoNguyenTo(arr, n, viTri, &soLuong))
            {
                printf("So nguyen to xuat hien %d lan tai cac vi tri: ", soLuong);
                for (int i = 0; i < soLuong; i++)
                {
                    printf("%d ", viTri[i]);
                }
                printf("\n");
            }
            else
            {
                printf("Khong co so nguyen to trong day\n");
            }
            break;
        case 15:
            if (timSoChinhPhuong(arr, n, viTri, &soLuong))
            {
                printf("So chinh phuong xuat hien %d lan tai cac vi tri: ", soLuong);
                for (int i = 0; i < soLuong; i++)
                {
                    printf("%d ", viTri[i]);
                }
                printf("\n");
            }
            else
            {
                printf("Khong co so chinh phuong trong day\n");
            }
            break;
        case 16:
            printf("Nhap gia tri can chen: ");
            scanf("%d", &x);
            printf("Nhap vi tri chen: ");
            scanf("%d", &k);
            chenPhanTu(arr, &n, x, k);
            printf("Day so sau khi chen: ");
            hienThiMang(arr, n);
            break;
        case 17:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &k);
            xoaPhanTu(arr, &n, k);
            printf("Day so sau khi xoa: ");
            hienThiMang(arr, n);
            break;
        case 18:
            xoaPhanTuGiaTri(arr, &n, 0);
            printf("Day so sau khi xoa cac phan tu co gia tri 0: ");
            hienThiMang(arr, n);
            break;
        case 19:
            for (int i = 0; i < n; i++)
            {
                if (arr[i] % 2 != 0)
                {
                    xoaPhanTu(arr, &n, i);
                    i--;
                }
            }
            printf("Day so sau khi xoa cac phan tu le: ");
            hienThiMang(arr, n);
            break;
        case 20:
            tiepTuc = false;
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\n");
    }

    return 0;
}
