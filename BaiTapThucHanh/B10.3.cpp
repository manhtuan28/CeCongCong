#include <iostream>
using namespace std;

class Person {
protected:
    string hoTen;
    string diaChi;
    int namSinh;
public:
    virtual void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin >> ws, diaChi);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    virtual void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
};

class CanBo : public Person {
private:
    string nghe;
    double luong;
public:
    void nhap() {
        Person::nhap();
        cout << "Nhap nghe: ";
        getline(cin >> ws, nghe);
        cout << "Nhap luong: ";
        cin >> luong;
    }

    void xuat() {
        Person::xuat();
        cout << "Nghe: " << nghe << endl;
        cout << "Luong: " << luong << endl;
    }

    double getLuong() {
        return luong;
    }
};

void nhapDanhSachCanBo(CanBo danhSach[], int& soLuong) {
    cout << "Nhap so luong can bo: ";
    cin >> soLuong;
    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin can bo thu " << i + 1 << ":" << endl;
        danhSach[i].nhap();
    }
}

void xuatDanhSachCanBo(CanBo danhSach[], int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        danhSach[i].xuat();
        cout << "--------------------" << endl;
    }
}

void canBoLuongCaoNhat(CanBo danhSach[], int soLuong) {
    double maxLuong = 0;
    for (int i = 0; i < soLuong; ++i) {
        if (danhSach[i].getLuong() > maxLuong) {
            maxLuong = danhSach[i].getLuong();
        }
    }
    cout << "Danh sach can bo co luong cao nhat:" << endl;
    for (int i = 0; i < soLuong; ++i) {
        if (danhSach[i].getLuong() == maxLuong) {
            danhSach[i].xuat();
            cout << "--------------------" << endl;
        }
    }
}

void sapXepCanBoTheoLuong(CanBo danhSach[], int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (danhSach[i].getLuong() > danhSach[j].getLuong()) {
                CanBo temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

int main() {
    const int MAX = 100;
    CanBo danhSachCanBo[MAX];
    int soLuongCanBo = 0;

    nhapDanhSachCanBo(danhSachCanBo, soLuongCanBo);

    cout << "\nDanh sach can bo:" << endl;
    xuatDanhSachCanBo(danhSachCanBo, soLuongCanBo);

    canBoLuongCaoNhat(danhSachCanBo, soLuongCanBo);

    sapXepCanBoTheoLuong(danhSachCanBo, soLuongCanBo);

    cout << "\nDanh sach can bo sau khi sap xep theo luong tang dan:" << endl;
    xuatDanhSachCanBo(danhSachCanBo, soLuongCanBo);

    return 0;
}

