#include <iostream>
#include <math.h>

using namespace std;

class PhuongTrinh2
{
private:
    double a, b;

public:
    void nhap();
    void giai();
};

void PhuongTrinh2::nhap()
{
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
}

void PhuongTrinh2::giai()
{
    if(a == 0){
        if(b == 0){
            cout <<"\nPhuong trinh vo so nghiem\n";
        }
        else {
            cout << "Phuong trinh vo nghiem\n";
        }
    }
    else {
        cout << "\nNghiem cua phuong trinh la: x= " << (-b/a) << "\n";
    }
}

int main()
{

    PhuongTrinh2 pt;
    pt.nhap();
    pt.giai();

    return 0;

}