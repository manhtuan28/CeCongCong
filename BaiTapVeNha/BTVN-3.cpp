#include <iostream>

using namespace std;

class SinhVien
{
private:
    char hoten[30];
    int namsinh;
    double diemc, diemjava, diemtkw;

public:
    void nhap();
    void xuat();
    double tinhtongdiem();
    static void sapxep(SinhVien arr[], int n);
};

void SinhVien::nhap()
{
    cout << "Nhập vào họ tên: ";
    cin >> hoten;
    cout << "Nhập vào năm sinh: ";
    cin >> namsinh;
    cout << "Nhập vào điểm C: ";
    cin >> diemc;
    cout << "Nhập vào điểm Java: ";
    cin >> diemjava;
    cout << "Nhập vào điểm thiết kế website: ";
    cin >> diemtkw;
}

void SinhVien::xuat()
{
    cout << "Họ tên của sv: " << hoten << endl;
    cout << "Năm sinh của sv: " << namsinh << endl;
    cout << "Điểm C: " << diemc << endl;
    cout << "Điểm Java: " << diemjava << endl;
    cout << "Điểm thiết kế website: " << diemtkw << endl;
    cout << "Tổng điểm: " << tinhtongdiem() << endl;
}

double SinhVien::tinhtongdiem()
{
    return diemc + diemjava + diemtkw;
}

void SinhVien::sapxep(SinhVien arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i].tinhtongdiem() > arr[j].tinhtongdiem())
            {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Nhập vào số lượng sinh viên: ";
    cin >> n;

    SinhVien *sv = new SinhVien[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Nhập thông tin sinh viên thứ " << i + 1 << ":" << endl;
        sv[i].nhap();
    }

    cout << "\nDanh sách sinh viên trước khi sắp xếp:" << endl;
    for (int i = 0; i < n; ++i)
    {
        sv[i].xuat();
        cout << endl;
    }

    SinhVien::sapxep(sv, n);

    cout << "\nDanh sách sinh viên sau khi sắp xếp theo tổng điểm:" << endl;
    for (int i = 0; i < n; ++i)
    {
        sv[i].xuat();
        cout << endl;
    }

    delete[] sv;

    return 0;
}