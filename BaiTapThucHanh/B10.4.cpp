#include <iostream>
#include <string>
using namespace std;

class CANBO {
protected:
    string maCanBo;
    string maDonVi;
    string hoTen;
    int namSinh;
public:
    CANBO() : maCanBo(""), maDonVi(""), hoTen(""), namSinh(0) {}

    CANBO(string maCB, string maDV, string ht, int ns) 
        : maCanBo(maCB), maDonVi(maDV), hoTen(ht), namSinh(ns) {}

    virtual void nhap() {
        cout << "Nhap ma can bo: ";
        getline(cin >> ws, maCanBo);
        cout << "Nhap ma don vi: ";
        getline(cin >> ws, maDonVi);
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    virtual void xuat() const {
        cout << "Ma can bo: " << maCanBo << endl;
        cout << "Ma don vi: " << maDonVi << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }

    string getMaDonVi() const {
        return maDonVi;
    }
};

class LUONG : public CANBO {
private:
    double phuCap;
    double heSoLuong;
    double baoHiem;
public:
    LUONG() : CANBO(), phuCap(0), heSoLuong(0), baoHiem(0) {}

    LUONG(string maCB, string maDV, string ht, int ns, double pc, double hsl, double bh) 
        : CANBO(maCB, maDV, ht, ns), phuCap(pc), heSoLuong(hsl), baoHiem(bh) {}

    void nhap() {
        CANBO::nhap();
        cout << "Nhap phu cap: ";
        cin >> phuCap;
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
        cout << "Nhap bao hiem: ";
        cin >> baoHiem;
    }

    void xuat() const {
        CANBO::xuat();
        cout << "Phu cap: " << phuCap << endl;
        cout << "He so luong: " << heSoLuong << endl;
        cout << "Bao hiem: " << baoHiem << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    double tinhLuong() const {
        return heSoLuong * 1150 + phuCap - baoHiem;
    }
};

void nhapDanhSachCanBo(LUONG danhSach[], int& soLuong) {
    cout << "Nhap so luong can bo: ";
    cin >> soLuong;
    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin can bo thu " << i + 1 << ":" << endl;
        danhSach[i].nhap();
    }
}

void xuatDanhSachCanBo(const LUONG danhSach[], int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        danhSach[i].xuat();
        cout << "--------------------" << endl;
    }
}

void inBangLuongTheoDonVi(const LUONG danhSach[], int soLuong) {
    string donVi;
    cout << "Nhap ma don vi can in bang luong: ";
    cin >> donVi;
    cout << "\nBang luong cua don vi " << donVi << ":" << endl;
    for (int i = 0; i < soLuong; ++i) {
        if (danhSach[i].getMaDonVi() == donVi) {
            danhSach[i].xuat();
            cout << "--------------------" << endl;
        }
    }
}

int main() {
    const int MAX = 100;
    LUONG danhSachCanBo[MAX];
    int soLuongCanBo = 0;

    nhapDanhSachCanBo(danhSachCanBo, soLuongCanBo);

    cout << "\nDanh sach can bo:" << endl;
    xuatDanhSachCanBo(danhSachCanBo, soLuongCanBo);

    inBangLuongTheoDonVi(danhSachCanBo, soLuongCanBo);

    return 0;
}

