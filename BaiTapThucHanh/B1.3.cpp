#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;

    cout << "Nhap gia tri a: ";
    cin >> a;
    cout << "Nhap gia tri b: ";
    cin >> b;
    cout << "Nhap gia tri c: ";
    cin >> c;

    if (a == 0)
    {
        cout << "Day khong phai la phuong trinh bac 2.\n";
        if (b != 0)
        {
            double x = -c / b;
            cout << "Day la phuong trinh bac 1 voi nghiem: x = " << x << endl;
        }
        else if (c == 0)
        {
            cout << "Phuong trinh co vo so nghiem.\n";
        }
        else
        {
            cout << "Phuong trinh vo nghiem.\n";
        }
    }
    else
    {
        double delta = b * b - 4 * a * c;

        if (delta > 0)
        {

            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co hai nghiem phan biet:\n";
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2 << "\n";
        }
        else if (delta == 0)
        {
            double x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x << "\n";
        }
        else
        {
            cout << "Phuong trinh vo nghiem thuc.\n";
        }
    }

    return 0;
}
