#include <iostream>

using namespace std;

int bonus(int);

int main()
{
    int m;
    cin >> m;
    int b = bonus(m);
    cout << m + b << endl;

    return 0;
}

int bonus(int c)
{
    int k = c / 7;
    int t = c % 7;

    if(k + t < 7)
    {

        cout << k + t << endl;
        return k;
    }
    else
    {
        return k + bonus(k + t);
    }
}
