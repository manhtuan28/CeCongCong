#include <iostream>
#include <conio.h>

using namespace std;

int main () {
    int a,b;
    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap so b: ";
    cin >> b;

    cout << "Tong 2 so: " << a + b << endl;
    cout << "Hieu 2 so: " << a - b << endl;
    cout << "Tich 2 so: " << a * b << endl;

    if(b == 0) {
        cout << "Loi";
    }
    else {
        cout << "Thuong 2 so: " << a / b << endl;
    }

    return 0;

}