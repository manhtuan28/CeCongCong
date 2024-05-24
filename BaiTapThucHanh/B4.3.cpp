#include <iostream>
#include <math.h>
using namespace std;

class giaithua
{
private:
    int n, s = 1;

public:
    int tinh()
    {

        cout << "nhap n: " << endl;
        cin >> n;
        if (n == 0 || n == 1)
        {
            return s;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                s *= i;
            }

            return s;
        }
    }
};

int main()
{
    giaithua g1;
    cout << endl
         << g1.tinh();
    
    return 0;
}
