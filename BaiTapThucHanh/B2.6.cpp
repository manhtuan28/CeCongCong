#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct PS
{
    int tuso, mauso;
};

void nhap(PS &a)
{

    cout << "nhap tu so ";
    cin >> a.tuso;
    do
    {
        cout << "nhap mau so " << endl;
        cin >> a.mauso;
        if (a.mauso == 0)
            cout << "khong hop le ";

    } while (a.tuso == 0);
}
void xuat(PS a)
{
    cout << endl
         << "phan so: " << a.tuso << "/" << a.mauso;
}

PS tong(PS a, PS b)
{
    PS c;
    c.mauso = a.mauso * b.mauso;
    c.tuso = a.tuso * b.mauso + b.tuso * a.mauso;
    return c;
}

PS hieu(PS a, PS b)
{
    PS c;
    c.mauso = a.mauso * b.mauso;
    c.tuso = a.tuso * b.mauso - b.tuso * a.mauso;
    return c;
}

PS tich(PS a, PS b)
{
    PS c;
    c.tuso = a.tuso * b.tuso;
    c.mauso = a.mauso * b.mauso;
    return c;
}

PS thuong(PS a, PS b)
{
    PS c;
    c.tuso = a.tuso * b.mauso;
    c.mauso = a.mauso * b.tuso;
    return c;
}

int ucln(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
        {
            a -= b; // a = a - b
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

PS rutgon(PS c)
{
    int u = ucln(c.tuso, c.mauso);
    c.tuso = c.tuso / u;
    c.mauso = c.mauso / u;
    return c;
}

int main()
{
    PS a, b, c;
    nhap(a);
    nhap(b);
    c = tong(a, b);
    c = rutgon(c);
    cout << "tong 2 phan so: ";
    xuat(c);
    c = hieu(a, b);
    c = rutgon(c);
    cout << "hieu 2 phan so: ";
    xuat(c);
    c = tich(a, b);
    c = rutgon(c);
    cout << "tich 2 phan so: ";
    xuat(c);
    c = thuong(a, b);
    c = rutgon(c);
    cout << "thuong 2 phan so: ";
    xuat(c);

    return 0;
}
// Theo NgọcCute