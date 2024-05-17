#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a, b;

    cout << "Nhap so nguyen thu nhat: ";
    cin >> a;
    cout << "Nhap so nguyen thu hai: ";
    cin >> b;

    int result = gcd(a, b);

    cout << "USCLN cua " << a << " va " << b << " la: " << result << endl;

    return 0;
}
// Theo ChaGPT