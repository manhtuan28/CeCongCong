#include <iostream>

using namespace std;

// Hàm nhập vào dãy số nguyên
void nhapDaySo(int arr[], int &n)
{
    cout << "Nhập số lượng phần tử trong dãy: ";
    cin >> n;
    cout << "Nhập các phần tử của dãy số: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
}

// Hàm hiển thị dãy số nguyên
void hienThiDaySo(int arr[], int n)
{
    cout << "Dãy số: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm tính tổng các phần tử trong dãy số
int tinhTong(int arr[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; ++i)
    {
        tong += arr[i];
    }
    return tong;
}

// Hàm tìm giá trị lớn nhất trong dãy số
int timGiaTriLonNhat(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Hàm sắp xếp dãy số theo chiều tăng dần
void sapXepDaySo(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    const int MAX_SIZE = 100; // Kích thước tối đa của mảng
    int arr[MAX_SIZE];
    int n;

    // Nhập dãy số
    nhapDaySo(arr, n);

    // Hiển thị dãy số
    hienThiDaySo(arr, n);

    // Tính tổng các phần tử trong dãy số
    int tong = tinhTong(arr, n);
    cout << "Tổng các phần tử trong dãy số: " << tong << endl;

    // Tìm giá trị lớn nhất trong dãy số
    int giaTriLonNhat = timGiaTriLonNhat(arr, n);
    cout << "Giá trị lớn nhất trong dãy số: " << giaTriLonNhat << endl;

    // Sắp xếp dãy số theo chiều tăng dần
    sapXepDaySo(arr, n);
    cout << "Dãy số sau khi sắp xếp theo chiều tăng dần: ";
    hienThiDaySo(arr, n);

    return 0;
}
