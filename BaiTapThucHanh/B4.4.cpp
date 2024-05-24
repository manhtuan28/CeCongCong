#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class SinhVien
{
private:
    string SBD, HoTen;
    int NamSinh;

public:
    void nhap();
    void xuat();
    int ns()
    {
        return NamSinh;
    }
};

void SinhVien::nhap()
{
    cout << "\nNhap vao so bao danh: ";
    cin >> SBD;
    cout << "\nNhap ho ten: ";
    cin >> HoTen;
    cout << "\nNhap vao nam sinh: ";
    cin >> NamSinh;
}

void SinhVien::xuat()
{
    cout << "\nSo bao danh: " << SBD << endl;
    cout << "\nHo ten: " << HoTen << endl;
    cout << "\nNam sinh: " << NamSinh << endl;
}

int main()
{

    SinhVien arr[10];
    int n;
    cout << "Nhap vao danh sach sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr[i].nhap();
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].xuat();
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].ns() > arr[j].ns())
            {
                SinhVien temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\nHien thi danh sach sau khi sap xep: \n";

    for (int i = 0; i < n; i++)
    {
        arr[i].xuat();
    }

    return 0;
}