/*
Bài Tập Về Nhà

Xây dựng lớp HangHoa gồm các thuộc tính: MaHang, TenHang, SoLuong, DonGia;

Các phương thức: Nhap(); HienThi(); ThanhTien() = SoLuong * DonGia;
*/

#include <iostream>

using namespace std;

class HangHoa
{
private:
    char MaHang[20],TenHang[60];
    int SoLuong, DonGia;

public:
    void Nhap();
    void HienThi();
    int ThanhTien();
};

void HangHoa::Nhap()
{
    cout << "Nhap vao ma hang: ";
    cin >> MaHang;
    cout << "Nhap vao ten hang: ";
    cin >> TenHang;
    cout << "Nhap vao so luong: ";
    cin >> SoLuong;
    cout << "Nha vao don gia: ";
    cin >> DonGia;
}

void HangHoa::HienThi()
{
    cout << "Ma hang: " << MaHang << endl;
    cout << "Ten hang: " << TenHang << endl;
    cout << "So luong: " << SoLuong << endl;
    cout << "Don gia: " << DonGia << endl;
}

int HangHoa::ThanhTien()
{
    return SoLuong * DonGia;
}

int main()
{

    HangHoa hh;

    hh.Nhap();
    hh.HienThi();

    int thanhTien = hh.ThanhTien();
    cout << "Thanh tien: " << thanhTien << endl;

    return 0;
}
