#include<iostream>
#include <fstream>

using namespace std;

ifstream inp;


int main()
{
	inp.open("test.txt");
	
	int a,b;
	inp >> a >> b;

	int *t = new int[a];
	int *p = new int[b];
	int *s = new int[b];

	for(int i = 0; i < a; i++)
	{
		inp >> t[i];
	}
	
	int *q = new int[b];
	int c,d,sum = 0;
	for(int i  = 0; i < b; i++)
	{
		inp >> c >> d;
		p[i] = c;
		s[i] = d;
		if(c < d)
		{
			for(int j = c-1; j <= d-1; j++)
			{
				sum = sum + t[j];
			}
			q[i] = sum;
			sum = 0;
		}
		else if(c == d)
		{
			q[i] = t[c-1];

		}
		else
		{
			for(int k = 0; k <=d-1; k++)
			{
				sum = sum + t[k];
			}
			for(int k = c-1; k < a; k++)
			{
				sum = sum + t[k];
			}
			q[i] = sum;
			sum = 0;
		}
	}

	int max = q[0];
	int e = 0;
	for(int i = 1; i < b; i++)
	{
		if(q[i] > max)
		{
			max = q[i];
			e = i;
		}
	}

	cout << "Max_range: (" << p[e] << ", " << s[e] << ");"; 

	delete [] t;
	t = NULL;

	delete [] q;
	q = NULL;

	delete [] p;
	p = NULL;

	delete [] s;
	s = NULL;

	cout << "Value: " << max << endl;
	

	return 0;
}
