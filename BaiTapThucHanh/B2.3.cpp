#include <iostream>

using namespace std;

// Hàm nhập vào mảng số nguyên và trả về tham chiếu tới mảng đó
int (&nhapMang(int (&arr)[100], int &n))[100]
{
    cout << "Nhập số lượng phần tử trong mảng: ";
    cin >> n;
    cout << "Nhập các phần tử của mảng: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    return arr;
}

// Hàm hiển thị mảng số nguyên
void hienThiMang(const int arr[], int n)
{
    cout << "Mảng số: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm sắp xếp mảng theo chiều tăng dần
void sapXepMang(int arr[], int n)
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
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int n;

    // Nhập mảng
    int(&refArr)[100] = nhapMang(arr, n);

    // Hiển thị mảng
    hienThiMang(refArr, n);

    // Sắp xếp mảng theo chiều tăng dần
    sapXepMang(refArr, n);
    cout << "Mảng sau khi sắp xếp theo chiều tăng dần: ";
    hienThiMang(refArr, n);

    return 0;
}
// Theo ChaGPT