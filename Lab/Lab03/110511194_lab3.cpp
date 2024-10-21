#include <iostream>

using namespace std;

int f1(int ,int);

int main()
{
    int a,b,c;
    cin >> a >> b;
    c = f1(a,b);



    return 0;
}

int f1(int a, int b)
{
    cout << a / b << " " << a % b << endl;

    if(a % b == 0)
    {
        cout << b;
        return a / b;
    }
    else
    {
        return f1(b,a % b);
    }
}
