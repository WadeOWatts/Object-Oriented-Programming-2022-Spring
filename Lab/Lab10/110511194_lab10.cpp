#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inp;
    inp.open("input.txt");

    vector<char> v;
	char next;
    while(inp >> next)
    {
        v.push_back(next);
    }

    vector<char>::iterator p,q;
    for(p = v.begin();p != v.end();p++)
    {
        for(q = p+1;q != v.end();q++)
        {
            if(*p == *q)
            {
                *p = '1';
                *q = '1';
                break;
            }
        }
    }

    p = v.begin();

    while(p != v.end())
    {
        if(*p == '1')
        {
            for(q = p+1; q != v.end();q++)
            {
                *(q-1) = *q;
            }

            v.pop_back();
        }
        else
            p++;

    }

    for(p = v.begin();p != v.end(); p++)
    {
        cout << *p;
        if(p != v.end()-1)
            cout << " ";
    }
    cout << endl;
    sort(v.begin(),v.end());

    for(p = v.begin();p != v.end(); p++)
    {
        cout << *p;
        if(p != v.end()-1)
            cout << " ";
    }
	cout << endl;

    inp.close();

    return 0;
}
