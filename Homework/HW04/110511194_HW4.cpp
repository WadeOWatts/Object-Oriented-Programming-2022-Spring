#include<iostream>
#include <string>

using namespace std;

class operators
{
	public:
		void add(istream& ins,int a);
		void sub(istream& ins,int a);
		void mul(istream& ins,int a);
		void div(istream& ins,int a);
		void less(istream& ins,int a);
		void neg(istream& ins, int a);
	private:
		int b,c,d;
};

int main()
{
	char o;
	string sym;
	int a;
	operators t;
	cin >> o >> sym;

	while(o != 'S')
	{
		cin >> a;

		if(o == 'a')
			t.add(cin,a);
		else if(o == 's')
			t.sub(cin,a);
		else if(o == 'm')
			t.mul(cin,a);
		else if(o == 'd')
			t.div(cin,a);
		else if(o == 'l')
			t.less(cin,a);
		else if(o == 'n')
			t.neg(cin,a);
	
		cin >> o >> sym;
		if (o == 'S')
			break;
	}
	return 0;
}


void operators::add(istream& ins,int a)
{
	ins >> b >> c >> d;
	cout << (a * d + b * c) << "/" << (b * d) << endl;
	return;
}
void operators::sub(istream& ins,int a)
{
	ins >> b >> c >> d;
	cout << (a * d - b * c) << "/" << (b * d) << endl;
	return;
}
void operators::mul(istream& ins,int a)
{
	ins >> b >> c >> d;
	cout << (a * c) << "/" << (b * d) << endl;
	return;
}
void operators::div(istream& ins,int a)
{
	ins >> b >> c >> d;
	cout << (a * d) <<  "/" << (b * c) << endl;
	return;
}
void operators::less(istream& ins,int a)
{
	ins >> b >> c >> d;
	if(a * d < c * b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return;
}
void operators::neg(istream& ins,int a)
{
	ins >> b;
	cout << -a << "/" << b << endl;
	return;
}
