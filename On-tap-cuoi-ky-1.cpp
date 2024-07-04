// By Tuancute
/* Lớp khách hàng (KhachHang):
Các thuộc tính: Tên khách, địa chỉ, năm sinh.
Các phương thức: thiết lập, nhập và hiển thị.
Lớp phiếu bán (PhienBan) kế thừa từ lớp khách hàng:
Các thuộc tính: tên mặt hàng, số lượng, giá bán, giảm giá.
Các phương thức: thiết lập, nhập, hiển thị, thành tiền = Số lượng * (đơn giá - giảm giá)+ 10%* Số lượng * (đơn giá
- giảm giá), phương thức sử dụng nạp chồng toán tử để so sánh 2 đối tượng theo giá bán.
Chương trình chính thực hiện các yêu cầu sau:
- Nhập danh sách n đổi tượng phiếu bán.
- Hiển thị danh sách ra màn hình.
- Hiển thị danh sách các phiếu bán có số lượng >= 100.
- Hiển thị danh sách các các phiếu bán theo chiều tăng dần của giá bán sử dụng nạp chồng toán tử để so sánh.
*/

#include <iostream>
using namespace std;

class KhachHang {
protected:
    string tenKhach;
    string diaChi;
    int namSinh;

public:
    KhachHang() {}

    KhachHang(string ten, string diachi, int namsinh) 
        : tenKhach(ten), diaChi(diachi), namSinh(namsinh) {}

    void nhap() {
        cout << "Nhap ten khach: ";
        cin.ignore();
        getline(cin, tenKhach);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    void hienThi() {
        cout << "Ten khach: " << tenKhach << "\n";
        cout << "Dia chi: " << diaChi << "\n";
        cout << "Nam sinh: " << namSinh << "\n";
    }
};

class PhieuBan : public KhachHang {
private:
    string tenMatHang;
    int soLuong;
    float giaBan;
    float giamGia;

public:
    PhieuBan() {}

    PhieuBan(string tenkh, string diachi, int namsinh, string tenMH, int sl, float gb, float gg)
        : KhachHang(tenkh, diachi, namsinh), tenMatHang(tenMH), soLuong(sl), giaBan(gb), giamGia(gg) {}

    void nhap() {
        KhachHang::nhap();
        cout << "Nhap ten mat hang: ";
        cin.ignore();
        getline(cin, tenMatHang);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap gia ban: ";
        cin >> giaBan;
        cout << "Nhap giam gia: ";
        cin >> giamGia;
    }

    void hienThi() {
        KhachHang::hienThi();
        cout << "Ten mat hang: " << tenMatHang << "\n";
        cout << "So luong: " << soLuong << "\n";
        cout << "Gia ban: " << giaBan << "\n";
        cout << "Giam gia: " << giamGia << "\n";
        cout << "Thanh tien: " << tinhTien() << "\n";
    }

    float tinhTien() {
        return soLuong * (giaBan - giamGia) + 0.1 * soLuong * (giaBan - giamGia);
    }

    bool operator<(PhieuBan& pb) {
        return tinhTien() < pb.tinhTien();
    }

    int getSL() {
        return soLuong;
    }
};

void nhapDS(PhieuBan ds[], int n) {
    for (int i = 0; i < n; ++i) {
        ds[i].nhap();
    }
}

void hienThiDS(PhieuBan ds[], int n) {
    for (int i = 0; i < n; ++i) {
        ds[i].hienThi();
        cout << "----------------------\n";
    }
}

void hienThiDS100(PhieuBan ds[], int n) {
    for (int i = 0; i < n; ++i) {
        if (ds[i].getSL() >= 100) {
            ds[i].hienThi();
            cout << "----------------------\n";
        }
    }
}

void sapXep(PhieuBan ds[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[j] < ds[i]) {
                PhieuBan temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phieu ban: ";
    cin >> n;

    PhieuBan danhSach[n];

    nhapDS(danhSach, n);

    cout << "\nDanh sach phieu ban:\n";
    hienThiDS(danhSach, n);

    cout << "\nDanh sach phieu ban co so luong >= 100:\n";
    hienThiDS100(danhSach, n);

    cout << "\nDanh sach phieu ban theo chieu tang dan cua thanh tien:\n";
    sapXep(danhSach, n);
    hienThiDS(danhSach, n);

    return 0;
}

// By Tuancute
