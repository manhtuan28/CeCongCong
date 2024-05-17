#include <iostream>

using namespace std;

int USCLN(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int abs(int n) {
    return (n < 0) ? -n : n;
}

int BSCNN(int a, int b) {
    return abs(a * b) / USCLN(a, b);
}

int main() {
    int a, b;
    cout << "Nhap so nguyen a: ";
    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;

    int uscln_result = USCLN(a, b);
    int bscnn_result = BSCNN(a, b);

    cout << "Uoc chung lon nhat cua " << a << " và " << b << " là: " << uscln_result << endl;
    cout << "Boi so chung lon nhat cua " << a << " và " << b << " là: " << bscnn_result << endl;

    return 0;
}

