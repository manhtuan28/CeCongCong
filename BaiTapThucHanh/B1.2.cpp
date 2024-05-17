#include <iostream>

using namespace std;

int main() {
    double a, b;
    

    cout << "Nhap gia tri a: ";
    cin >> a;
    cout << "Nhap gia tri b: ";
    cin >> b;

    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem.\n";
        } else {
            cout << "Phuong trinh vo nghiem.\n";
        }
    } else {
        double x = -b / a;
        cout << "Nghiem cua phuong trinh la: x = " << x << endl;
    }

    return 0;
}
// Theo ChaGPT