/*
Bài Tập Về Nhà

Xây dựng lớp SinhVien thuộc tính: HoTen, NamSinh, DiemC, DiemJava, DiemTKW;

Các phương thức gồm: Nhap(), HienThi(), TinhDTB();

*/

#include <iostream>

using namespace std;

class SinhVien
{

private:
    char HoTen[50];
    int NamSinh;
    float DiemC, DiemJava, DiemTKW;

public:
    void Nhap();
    void HienThi();
    float TinhDTB();
};

void SinhVien::Nhap()
{
    cout << "Nhap Ho va ten: ";
    cin >> HoTen;
    cout << "Nhap Nam sinh: ";
    cin >> NamSinh;
    cout << "Nhap diem C: ";
    cin >> DiemC;
    cout << "Nhap diem Java: ";
    cin >> DiemJava;
    cout << "Nhap diem TKW: ";
    cin >> DiemTKW;
}

void SinhVien::HienThi()
{
    cout << "Ho va ten: " << HoTen << endl;
    cout << "Nam sinh: " << NamSinh << endl;
    cout << "Diem C: " << DiemC << endl;
    cout << "Diem Java: " << DiemJava << endl;
    cout << "Diem TKW: " << DiemTKW << endl;
}

float SinhVien::TinhDTB() {
    return (DiemC + DiemJava + DiemTKW) / 3;
}

int main()
{
    SinhVien sv;
    sv.Nhap();
    sv.HienThi();
    cout << "Diem trung binh: " << sv.TinhDTB() << endl;
    
    return 0;
}
// Theo ChaGPT