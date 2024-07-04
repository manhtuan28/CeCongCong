// Tuancute - ChatGPT 4.0

/* Xây dựng lớp SANPHAM gồm:
Thuộc tính: tên sản phẩm, giá thành
Phương thức: hàm nhập và hàm hiển thị
Xây dựng lớp SANXUAT kể thừa từ lớp SANPHAM gồm:
Thuộc tính: tên công nhân, số lượng sản phẩm, phụ cấp.
Phương thức: hàm nhập, hiển thị, lương = số sản phẩm x 10% giá thành + phụ cấp.
Toán từ > để so sánh 2 đổi tượng theo lương
Chương trình chính thực hiện các yêu cầu sau:
- Nhập danh sách đổi tượng sản xuất (SANXUAT)
- Hiển thị danh sách đổi tượng sản xuất.
- Hiển thị ra danh sách các công nhân có sổ lượng sản phẩm>=100
- Sắp xếp danh sách theo chiều tăng dần lương nhân viên.
*/

#include <iostream>
using namespace std;

class SANPHAM {
protected:
    string tenSanPham;
    double giaThanh;

public:
    void nhap() {
        cout << "Nhap ten san pham: ";
        cin >> tenSanPham;
        cout << "Nhap gia thanh: ";
        cin >> giaThanh;
    }

    void hienThi() {
        cout << "Ten san pham: " << tenSanPham << ", Gia thanh: " << giaThanh << endl;
    }
};

class SANXUAT : public SANPHAM {
private:
    string tenCongNhan;
    int soLuongSanPham;
    double phuCap;

public:
    void nhap() {
        SANPHAM::nhap();
        cout << "Nhap ten cong nhan: ";
        cin >> tenCongNhan;
        cout << "Nhap so luong san pham: ";
        cin >> soLuongSanPham;
        cout << "Nhap phu cap: ";
        cin >> phuCap;
    }

    void hienThi() {
        SANPHAM::hienThi();
        cout << "Ten cong nhan: " << tenCongNhan << ", So luong san pham: " << soLuongSanPham << ", Phu cap: " << phuCap << endl;
    }

    double luong() {
        return soLuongSanPham * 0.1 * giaThanh + phuCap;
    }

    bool lonHon(SANXUAT &other) {
        return this->luong() > other.luong();
    }

    int laySoLuong() {
        return soLuongSanPham;
    }
};

void nhapDanhSach(SANXUAT danhSach[], int &n) {
    cout << "Nhap so luong cong nhan san xuat: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cong nhan thu " << i + 1 << ":\n";
        danhSach[i].nhap();
    }
}

void hienThiDanhSach(SANXUAT danhSach[], int n) {
    for (int i = 0; i < n; ++i) {
        danhSach[i].hienThi();
    }
}

void hienThiCongNhanSanPhamLonHon100(SANXUAT danhSach[], int n) {
    for (int i = 0; i < n; ++i) {
        if (danhSach[i].laySoLuong() >= 100) {
            danhSach[i].hienThi();
        }
    }
}

void sapXepDanhSach(SANXUAT danhSach[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (danhSach[i].luong() > danhSach[j].luong()) {
                SANXUAT temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

int main() {
    const int MAX = 100;
    SANXUAT danhSach[MAX];
    int n;

    nhapDanhSach(danhSach, n);
    cout << "\nDanh sach cong nhan san xuat:\n";
    hienThiDanhSach(danhSach, n);

    cout << "\nDanh sach cong nhan co so luong san pham >= 100:\n";
    hienThiCongNhanSanPhamLonHon100(danhSach, n);

    sapXepDanhSach(danhSach, n);
    cout << "\nDanh sach cong nhan sau khi sap xep theo luong tang dan:\n";
    hienThiDanhSach(danhSach, n);

    return 0;
}

// Tuancute - ChatGPT 4.0
