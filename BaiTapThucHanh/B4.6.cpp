#include <iostream>
#include <string>

using namespace std;

class HocSinh
{
private:
    string HoTen;
    int NamSinh;
    double Toan, Ly, Hoa;

public:
    void Nhap();
    void xuat();
    double TinhTong();
};

void HocSinh::Nhap()
{
    cout << "Nhap vao ho ten: ";
    cin >> HoTen;
    cout << "Nhap nam sinh: ";
    cin >> NamSinh;
    cout << "Nhap vao diem toan: ";
    cin >> Toan;
    cout << "Nhap vao diem ly: ";
    cin >> Ly;
    cout << "Nhap vao diem hoa: ";
    cin >> Hoa;
}

void HocSinh::xuat()
{
    cout << "Ho ten sinh vien: " << HoTen << endl;
    cout << "Nam sinh sinh vien: " << NamSinh << endl;
    cout << "Diem toan: " << Toan << endl;
    cout << "Diem ly: " << Ly << endl;
    cout << "Diem hoa: " << Hoa << endl;
}

double HocSinh::TinhTong()
{
    return Toan + Ly + Hoa;
}

int main()
{
    HocSinh arr[10];
    int n;
    cout << "Nhap vao danh sach sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr[i].Nhap();
    }

    for (int i = 0; i < n; i++)
    {
        arr[i].xuat();
    }

    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i].TinhTong() > arr[j].TinhTong())
                {
                    HocSinh temp;
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
}