#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Nhap gia tri n: ";
    cin >> n;

    if (n < 1)
    {
        cout << "n phai lon hon hoac bang 1." << endl;
        return 1;
    }

    int sum = n * (n + 1) / 2;

    cout << "Tong cac so tu 1 den " << n << " la: " << sum << endl;

    return 0;
}
// Theo ChaGPT