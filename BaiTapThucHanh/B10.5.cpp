#include <iostream>
#include <string>
using namespace std;

class Nguoi {
protected:
    string maSo;
    string hoTen;
    double luong;
public:
    Nguoi() : maSo(""), hoTen(""), luong(0) {}

    Nguoi(string ms, string ht, double l) : maSo(ms), hoTen(ht), luong(l) {}

    virtual void nhap() {
        cout << "Nhap ma so: ";
        getline(cin >> ws, maSo);
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
    }

    virtual void xuat() const {
        cout << "Ma so: " << maSo << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Luong: " << luong << endl;
    }

    virtual void tinhLuong() = 0;
};

class Bienche : public Nguoi {
private:
    double heSoLuong;
    double phuCapChucVu;
public:
    Bienche() : Nguoi(), heSoLuong(0), phuCapChucVu(0) {}

    Bienche(string ms, string ht, double hsl, double pccv) 
        : Nguoi(ms, ht, 0), heSoLuong(hsl), phuCapChucVu(pccv) {}

    void nhap() {
        Nguoi::nhap();
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
        cout << "Nhap phu cap chuc vu: ";
        cin >> phuCapChucVu;
    }

    void xuat() const {
        Nguoi::xuat();
        cout << "He so luong: " << heSoLuong << endl;
        cout << "Phu cap chuc vu: " << phuCapChucVu << endl;
    }

    void tinhLuong() {
        luong = heSoLuong * 1150 + phuCapChucVu;
    }
};

class Hopdong : public Nguoi {
private:
    double tienCong;
    int soNgayLamViec;
    double heSoVuotGio;
public:
    Hopdong() : Nguoi(), tienCong(0), soNgayLamViec(0), heSoVuotGio(0) {}

    Hopdong(string ms, string ht, double tc, int snlv, double hsv) 
        : Nguoi(ms, ht, 0), tienCong(tc), soNgayLamViec(snlv), heSoVuotGio(hsv) {}

    void nhap() {
        Nguoi::nhap();
        cout << "Nhap tien cong lao dong: ";
        cin >> tienCong;
        cout << "Nhap so ngay lam viec trong thang: ";
        cin >> soNgayLamViec;
        cout << "Nhap he so vuot gio: ";
        cin >> heSoVuotGio;
    }

    void xuat() const {
        Nguoi::xuat();
        cout << "Tien cong lao dong: " << tienCong << endl;
        cout << "So ngay lam viec trong thang: " << soNgayLamViec << endl;
        cout << "He so vuot gio: " << heSoVuotGio << endl;
    }

    void tinhLuong() {
        luong = tienCong * soNgayLamViec * heSoVuotGio;
    }
};

void nhapDanhSachNguoi(Nguoi* danhSach[], int& soLuong) {
    cout << "Nhap so luong vien chuc: ";
    cin >> soLuong;
    for (int i = 0; i < soLuong; ++i) {
        int loai;
        cout << "Nhap loai vien chuc (1-Bienche, 2-Hopdong): ";
        cin >> loai;
        if (loai == 1) {
            danhSach[i] = new Bienche();
        } else {
            danhSach[i] = new Hopdong();
        }
        danhSach[i]->nhap();
        danhSach[i]->tinhLuong();
    }
}

void xuatDanhSachNguoi(Nguoi* danhSach[], int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        danhSach[i]->xuat();
        cout << "--------------------" << endl;
    }
}

int main() {
    const int MAX = 100;
    Nguoi* danhSachNguoi[MAX];
    int soLuongNguoi = 0;

    nhapDanhSachNguoi(danhSachNguoi, soLuongNguoi);

    cout << "\nDanh sach vien chuc:" << endl;
    xuatDanhSachNguoi(danhSachNguoi, soLuongNguoi);

    for (int i = 0; i < soLuongNguoi; ++i) {
        delete danhSachNguoi[i];
    }

    return 0;
}

