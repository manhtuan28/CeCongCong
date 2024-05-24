#include <iostream>
#include <string>

using namespace std;

class CanBo
{
private:
    string HoTen;
    int NgaySinh, SoNgayLamViec;

public:
    void nhap();
    void xuat();
    int TinhLuong();
};

void CanBo::nhap()
{
    cout << "Nhap vao ho ten: ";
    cin >> HoTen;
    cout << "Nhap vao ngay sinh: ";
    cin >> NgaySinh;
    cout << "Nhap vao so ngay lam viec: ";
    cin >> SoNgayLamViec;
}

void CanBo::xuat()
{
    cout << "Ho ten cua ban: " << HoTen << endl;
    cout << "Ngay sinh cua ban: " << NgaySinh << endl;
    cout << "So ngay lam viec: " << SoNgayLamViec << endl;
}

int CanBo::TinhLuong()
{
    return SoNgayLamViec * 50000;
}

int main()
{
    CanBo cb;
    cb.nhap();
    cb.xuat();

    cout << "Luong cua ban: " << cb.TinhLuong();

    return 0;
}