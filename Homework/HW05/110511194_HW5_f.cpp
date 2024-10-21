#include <iostream>
#include <string>
using namespace std;

class DecimalBookInfo
{
	public:
		friend bool greater_test(const DecimalBookInfo& b1,const DecimalBookInfo& b2);
		friend bool greater_equal_(const DecimalBookInfo& b1, const DecimalBookInfo& b2);
		friend bool less_test(const DecimalBookInfo& b1,const DecimalBookInfo& b2);
		friend bool less_equal_(const DecimalBookInfo& b1,const DecimalBookInfo& b2);
		void get_name();
		void get_cn();
		void output();
	private:
		string name;
		double cn;
};

int main()
{
	
	DecimalBookInfo a, b;
	a.get_name();
	a.get_cn();
	b.get_name();
	b.get_cn();
	
	if(less_test(a,b))
	{
		a.output();
		cout << " < ";
		b.output();
		cout << endl;
	}
	if(less_test(b,a))
	{
		b.output();
		cout << " < ";
		a.output();
		cout << endl;
	}
	if(less_equal_(a,b))
	{
		a.output();
		cout << " <= ";
		b.output();
		cout << endl;
	}
	if(less_equal_(b,a))
	{
		b.output();
		cout << " <= ";
		a.output();
		cout << endl;
	}
	if(greater_test(a,b))
	{
		a.output();
		cout << " > ";
		b.output();
		cout << endl;
	}
	if(greater_test(b,a))
	{
		b.output();
		cout << " > ";
		a.output();
		cout << endl;
	}
	if(greater_equal_(a,b))
	{
		a.output();
		cout << " >= ";
		b.output();
		cout << endl;
	}
	if(greater_equal_(b,a))
	{
		b.output();
		cout << " >= ";
		a.output();
		cout << endl;
	}

	return 0;
}

void DecimalBookInfo::get_name()
{
	cin >> name;
	return;
}

void DecimalBookInfo::get_cn()
{
	cin >> cn;
	return;
}
void DecimalBookInfo::output()
{
	cout << name;
	return;
}
bool greater_test(const DecimalBookInfo& b1,const DecimalBookInfo& b2)
{
	return(b1.cn > b2.cn);
}
bool greater_equal_(const DecimalBookInfo& b1,const DecimalBookInfo& b2)
{
	return(b1.cn>= b2.cn);
}
bool less_test(const DecimalBookInfo& b1,const DecimalBookInfo& b2)
{
	return(b1.cn < b2.cn);
}
bool less_equal_(const DecimalBookInfo& b1,const DecimalBookInfo& b2)
{
	return(b1.cn<= b2.cn);
}
