#include <iostream>
#include <conio.h>

using namespace std;

class A
{
	private:
		int n;
	public:
		void nhap(){
			cout << "Nhap n: ";
			cin >> n;
		}
		
		void hienthi(){
			cout << "Gia tri n = " << n << endl;
		}
		
		int getn(){
			return n;
		}
};

class B : public A
{
	private:
		int m;
	
	public:
		void nhap()
		{
			A::nhap();
			cout << "Nhap m = ";
			cin >> m;
		}
	
		void hienthi()
		{
			A::hienthi();
			cout << "Gia tri m = " << m << endl;
			cout << "Tich cua m va n = " << tich() << endl;
		}
		
		int tich()
		{
			return m * getn();
		}
};

int main ()
{
	B ob;
	ob.nhap();
	ob.hienthi();
	return 0;
}

