#include<iostream>
using namespace std;

template<class T>
void deleteRepeats(T, int&);

int main(){
    int size;

    char a[10];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'a';
    a[3] = 'c';
    a[4] = 'e';
    a[5] = 'e';
    a[6] = 'g';
    a[7] = 'e';
    size = 8;
    deleteRepeats(a, size);
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << "\n";

    int b[10];
    b[0] = 1;
    b[1] = 1;
    b[2] = 5;
    b[3] = 9;
    b[4] = 1;
    size = 5;
    deleteRepeats(b, size);
    for(int i = 0; i < size; i++)
        cout << b[i] << " ";
    cout << "\n";

    return 0;
}

template<class T>
void deleteRepeats(T a, int& s)
{
    int S = 0;
    for(int i = 0;i < s-1;i++)
    {
        for(int j = i+1;j < s;j++)
        {
            if(a[j] == a[i])
            {
                for(int k = j+1;k < s;k++)
                {
                    a[k-1] = a[k];
                }
                s--;
            }
        }
    }
}
