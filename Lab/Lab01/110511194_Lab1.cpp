#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n != 0)
	{
		for(int i = 2; i <= n; i++)
		{
			if(n % i == 0)
			{
				cout << i;
				n = n / i;
				if(n != 1)
				{
					cout << "*";
				}
				break;
			}
		}
		if(n == 1)
		{
			cout << endl;
			cin >> n;
		}
	}
	return 0;
}

