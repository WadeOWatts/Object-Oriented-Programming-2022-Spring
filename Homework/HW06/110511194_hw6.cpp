#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstddef>
#include <cstdlib>
using namespace std;

class poly
{
	public:
		poly();
		poly(const poly& c);
		~poly();
		friend poly operator +(const poly& a, const poly& b);
		friend poly operator -(const poly& a, const poly& b);
		friend poly operator *(const poly& a, const poly& b);
		friend ostream& operator <<(ostream& outs, const poly& a);
		void operator =(const poly& right);
		double get_value(vector<double> v);
		int get_size(int);

	private:
		double *value;
		int size;
};

poly::poly()
{
	value = new double;
	*value = 0;
	size = 1;
}

poly::poly(const poly& c)
{
	value = new double[c.size];
	for(int i = 0; i < c.size;i++)
	{
		value[i] = c.value[i];
	}
}

poly::~poly()
{
	delete [] value;
}

void poly::operator =(const poly& right)
{
	int newl = right.size;
	if(newl > size)
	{
		delete [] value;
		size = newl;
		value = new double[newl];
	}
	
	for(int i = 0; i < newl;i++)
		value[i] = right.value[i];
}

double poly::get_value(vector<double> v)
{
	value = new double[size];
	for(int i = 0; i < size;i++)
	{
		value[i] = v[size-i-1];
	}
}
int poly::get_size(int l)
{
	size = l;
}

poly operator +(const poly& a, const poly& b)
{
	poly temp,tr;
	bool t = (a.size >= b.size);
	if(t)
	{
		temp.size = a.size;
		temp.value = new double[temp.size];
		for(int i = 0; i < b.size; i++)
		{
			temp.value[i] = a.value[i] + b.value[i];
		}
		for(int i = b.size; i < a.size;i++)
		{
			temp.value[i] = a.value[i];
		}
	}
	else
	{
		temp.size = b.size;
		temp.value = new double[temp.size];
		for(int i = 0; i < a.size; i++)
			temp.value[i] = a.value[i] + b.value[i];
		for(int i = a.size;i < b.size;i++)
			temp.value[i] = b.value[i];
	}
	tr.value = new double[temp.size];
	tr.size = temp.size;
	for(int i = 0; i < temp.size; i++)
	{
		tr.value[i] = temp.value[temp.size-i-1];
	}
	return tr;
}
poly operator -(const poly& a, const poly& b)
{
	poly temp,tr;
	temp.value = new double[a.size];
	temp.value[0] = a.value[0] - b.value[0];
	for(int i = 1; i < a.size;i++)
		temp.value[i] = a.value[i];
	tr.value = new double[a.size];
	tr.size = a.size;
	for(int i = 0;i < a.size;i++)
		tr.value[i] = temp.value[a.size-1-i];
	return tr;
}
poly operator *(const poly& a, const poly& b)
{
	poly temp,tr;
	temp.size = (a.size - 1) + (b.size - 1) + 1;
	temp.value = new double[temp.size];
	for(int i = 0;i < temp.size;i++)
	{
		temp.value[i] = 0;
	}
	for(int i  = 0;i < b.size;i++)
	{
		for(int j = 0; j < a.size;j++)
		{
			temp.value[i + j] = temp.value[i + j] + b.value[i] * a.value[j];
		}
	}
	tr.size = temp.size;
	tr.value = new double[tr.size];
	for(int i = 0; i < tr.size;i++)
	{
		tr.value[i] = temp.value[temp.size - i - 1];
	}
	return tr;
}
ostream& operator <<(ostream& outs, const poly& a)
{
	for(int i = 0;i < a.size;i++)
	{
		cout << a.value[i] << " ";
	}
	return outs;

}
int main()
{
	ifstream inp;
	inp.open("poly_math.txt");
	int i;
	string emp;
	inp >> i;
	getline(inp,emp);
	for(int j = 1; j <= i;j++)
	{
		string s,type;
		char sym;
		int l1 = 0,l2 = 0;
		double v1,v2;
		vector<double> value1,value2;

		getline(inp,s);
		istringstream stream(s);
		stream >> type;
		while(stream >> v1)
		{
			value1.push_back(v1);
			++l1;
		}

		getline(inp,s);
		istringstream t(s);
		t >> type >> sym;

		getline(inp,s);
		istringstream r(s);
		r >> type;
		while(r >> v2)
		{
			value2.push_back(v2);
			++l2;
		}
		getline(inp,s);
		
		poly p1,p2,p3;
		p1.get_size(l1);
		p2.get_size(l2);
		p1.get_value(value1);
		p2.get_value(value2);

		if(sym == '+')
		{
			p3 = p1 + p2;
		}
		else if(sym == '-')
		{
			p3 = p1 - p2;
		}
		else
		{
			p3 = p1 * p2;
		}

		cout << p3 << endl;
	}

	return 0;
}
