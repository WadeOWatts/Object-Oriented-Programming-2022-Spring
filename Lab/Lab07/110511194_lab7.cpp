#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



class PolySeq
{
	public:
		PolySeq();
		PolySeq(int,double* ,int*);
		PolySeq Add(PolySeq);
		PolySeq Multiply(PolySeq);
		PolySeq Derivative();
		double Integral(int,int);
		double getvalue(int);
		void getce();
	private:
		int n;
		double* c;
		int* e;
};

int main()
{
	PolySeq P1,P2;
	
	P1.getce();
	P2.getce();
	int x1,x2;
	cin >> x1 >> x2;
	cout << endl;
	
	PolySeq a,m,d;
	a = P1.Add(P2);
	double aa = a.getvalue(x1);
	cout << aa << endl;

	m = P1.Multiply(P2);
	double mm = m.getvalue(x1);
	cout << mm << endl;

	d = P1.Derivative();
	double dd = d.getvalue(x1);
	cout << dd << endl;

	double i = P2.Integral(x1,x2);
	cout << i << endl;
	
	return 0;
}

void PolySeq::getce()
{
	cin >> n;
	c = new double[n];
	for(int i = n-1; i >= 0; i--)
		cin >> c[i];

	e = new int[n];
	for(int i = n-1; i >= 0;i--)
		cin >> e[i];	
}

PolySeq::PolySeq()
{
	n = 0;
	c = 0;
	e = 0;
}
PolySeq::PolySeq(int a,double* b ,int*d)
{
	n = a;
	c = b;
	e = d;
}

PolySeq PolySeq::Add(PolySeq P2)
{
	PolySeq temp;
	int e1 = 0,e2 = 0;

	for(int i = 0; i < n;i++)
	{
		if(e[i] > e1)
			e1 = e[i];
	}
	for(int i = 0;i < P2.n;i++)
	{
		if(P2.e[i] > e2)
			e2 = e[i];
	}
	
	if(e1 >= e2)
	{
		temp.n = n;
		temp.c = new double[n];
		for(int i = 0; i < n;i++)
			temp.c[i] = 0;
		for(int i = 0; i < P2.n;i++)
		{
			temp.c[P2.e[i]] = temp.c[P2.e[i]] +P2.c[i];
			
		}
		for(int i = 0;i < n;i++)
		{
			temp.c[e[i]] = temp.c[e[i]] + c[i];
			
		}
		temp.e = new int[n];
		for(int i = 0;i < n;i++)
			temp.e[i] = i;
	}
	else{
		temp.n = P2.n;
		temp.c = new double[P2.n];
		for(int i = 0;i < P2.n;i++)
			temp.c[i] = 0;
		for(int i = 0;i < n;i++)
			temp.c[e[i]] =temp.c[e[i]] +c[i];
		for(int i = 0;i < P2.n;i++)
			temp.c[P2.e[i]] =temp.c[P2.e[i]]+ P2.c[i];
		temp.e = new int[P2.n];
		for(int i = 0;i < P2.n;i++)
			temp.e[i] = i;
	}
	
	return temp;
	
}

PolySeq PolySeq::Multiply(PolySeq P2)
{
	PolySeq temp;
	temp.n = n + P2.n - 1;
	temp.c = new double[temp.n];
	for(int i = 0;i < temp.n;i++)
	{
		temp.c[i] = 0;
	}
	for(int i = 0;i < P2.n;i++)
	{
		for(int j = 0; j < n;j++)
			temp.c[P2.e[i]+e[j]] = temp.c[P2.e[i]+e[j]] + P2.c[i] * c[j];
	}
	temp.e = new int[temp.n];
	for(int i = 0;i < temp.n;i++)
		temp.e[i] = i;
	
	return temp;
}

double PolySeq::getvalue(int x)
{
	double sum = 0;
	for(int i = 0;i < n;i++)
	{
		sum = sum + c[i] * pow(x,e[i]);
			}
	return sum;
}
PolySeq PolySeq::Derivative()
{
	PolySeq temp;
	temp.n = n - 1;

	temp.c = new double[temp.n];
	temp.e = new int[temp.n];
	for(int i = 0;i < temp.n;i++)
	{
		int r = e[i] + 1,w = 0;
		for(int j = 0; j < n;j++)
		{
			if(e[j] == r)
				w = j;
				
		}
		temp.c[e[i]] = c[w] *( e[i]+1);
	}
	for(int i = 0;i < temp.n;i++)
		temp.e[i] = i;
	return temp;
}
double PolySeq::Integral(int x1,int x2)
{
	PolySeq temp;
	temp.n = n + 1;
	temp.e = new int[temp.n];
	for(int i = 0;i < temp.n;i++)
		temp.e[i] = i;
	temp.c = new double[temp.n];
	
	temp.c[0] = 0;

	for(int i = 0;i < n;i++){
		temp.c[e[i]+1] = c[i] * 1.00 /(e[i]+1) ;
			}

 return temp.getvalue(x2) -temp.getvalue(x1);

}
