#include <iostream>

using namespace std;

class HVUONG {
    protected:
        double canh;
    public:
        void nhap() {
            cout << "Nhap do dai canh hinh vuong: ";
            cin >> canh;
        }

        void hienthi() {
            cout << "Do dai canh hinh vuong: " << canh << endl;
            cout << "Dien tich hinh vuong: " << dientich() << endl;
            cout << "Chu vi hinh vuong: " << chuvi() << endl;
        }

        double dientich() {
            return canh * canh;
        }

        double chuvi() {
            return 4 * canh;
        }
};

class CHUNHAT : public HVUONG {
    private:
        double canh2;
    public:
        void nhap() {
            cout << "Nhap do dai canh thu nhat cua hinh chu nhat: ";
            cin >> canh;
            cout << "Nhap do dai canh thu hai cua hinh chu nhat: ";
            cin >> canh2;
        }

        void hienthi() {
            cout << "Do dai canh thu nhat cua hinh chu nhat: " << canh << endl;
            cout << "Do dai canh thu hai cua hinh chu nhat: " << canh2 << endl;
            cout << "Dien tich hinh chu nhat: " << dientich() << endl;
            cout << "Chu vi hinh chu nhat: " << chuvi() << endl;
        }

        double dientich() {
            return canh * canh2;
        }

        double chuvi() {
            return 2 * (canh + canh2);
        }
};

int main() {
    CHUNHAT hcn;
    hcn.nhap();
    hcn.hienthi();

    return 0;
}

