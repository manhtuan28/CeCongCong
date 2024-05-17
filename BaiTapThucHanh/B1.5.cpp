#include <iostream>

using namespace std;

unsigned long long factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;

    cout << "Nhap gia tri n: ";
    cin >> n;

    if (n < 0)
    {
        cout << "n phai lon hon hoac bang 0." << endl;
        return 1;
    }

    unsigned long long result = factorial(n);

    cout << n << "! = " << result << endl;

    return 0;
}
