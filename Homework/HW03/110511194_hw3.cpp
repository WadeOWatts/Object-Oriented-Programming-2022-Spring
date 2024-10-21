#include<iostream>

using namespace std;

char* deleteRepeat(int&, char*);

int main()
{
	int s1;
	cin >> s1;
	char* a = new char[s1];
	for(int i = 0; i < s1; i++)
	{
		cin >> a[i];
	}

	char* b;
	b = deleteRepeat(s1,a);


	
	cout << s1 << endl;
	for(int i = 0; i < s1; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;


	return 0;
}


char* deleteRepeat(int& s1, char* a)
{
	for(int i = 0; i < s1-1; i++)
	{
		for(int j =(i + 1); j < s1; j++)
		{
			if(a[i] == ' ')
				break;

			if(a[i] == a[j])
			{
				a[j] = ' ';
			}
			else
			{
				continue;
			}
		}
	}
	
	int k = 0;
	for(int i = 0; i < s1; i++)
	{
		if(isalpha(a[i]))
			k++;
	}
	char* b = {};
	b = new char[k];

	int c = 0;

	for(int i = 0; i < s1; i++)
	{
		if(isalpha(a[i]))
		{
			b[c] = a[i];
			c++;
		}
	}
	
	s1 = k;

	delete [] a;

	return b;
}
