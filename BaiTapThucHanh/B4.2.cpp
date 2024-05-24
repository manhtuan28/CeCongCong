#include <iostream>
#include <math.h>
using namespace std;

class PTB2
{
private:
    int a, b, c;
    float del;

public:
    void giaipt()
    {
        cout << "Nhap a,b,c: " << endl;
        cin >> a >> b >> c;
        if (a == 0)
        {
            if (b == 0 && c == 0)
                cout << endl
                     << "Phuong trinh vo so nghiem";
            else if (b == 0 && c != 0)
                cout << endl
                     << "Phuong trinh vo nghie,";
            else
                cout << endl
                     << "Phuong trinh co nghiem x= " << (float)-b / a;
        }

        else
            del = b * b - 4 * a * c;
        if (del < 0)
            cout << endl
                 << "Phuong trinh vo nghiem";
        else if (del == 0)
            cout << endl
                 << "Phuong trinh co nghiem kep x= " << (float)-b / 2 * a;
        else
            cout << endl
                 << "Phuong trinh có 2 nghiem phan biet x1= " << (float)(-b + sqrt(del)) / 2 * a << ", x2= " << (float)(-b - sqrt(del)) / 2 * a;
    }
};

int main()
{
    PTB2 pt1;
    pt1.giaipt();

    return 0;
}
