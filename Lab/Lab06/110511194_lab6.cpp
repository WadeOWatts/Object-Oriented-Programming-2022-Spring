#include <iostream>
using namespace std;

class Complex
{
	public:
		Complex();
		Complex(double re,double im);
		friend Complex operator +(const Complex& lhs,const Complex& rhs);
		friend Complex operator -(const Complex& lhs,const Complex& rhs);
		friend Complex operator *(const Complex& lhs,const Complex& rhs);
		friend Complex operator !(const Complex& c);
		friend bool operator ==(const Complex& lhs,const Complex& rhs);
		friend bool operator !=(const Complex& lhs,const Complex& rhs);
		friend istream& operator >>(istream& in,Complex& rhs);
		friend ostream& operator <<(ostream& out,const Complex& rhs);
	private:
		double r;
		double i;
};
Complex::Complex():r(0),i(0)
{
	
}
Complex::Complex(double re,double im)
{
	r = re;
	i = im;
}
Complex operator +(const Complex& lhs,const Complex& rhs)
{
	Complex temp;
	temp.r = lhs.r + rhs.r;
	temp.i = lhs.i + rhs.i;
	return temp;
}
Complex operator -(const Complex& lhs,const Complex& rhs)
{
	Complex temp;
	temp.r = lhs.r - rhs.r;
	temp.i = lhs.i - rhs.i;
	return temp;
}
Complex operator *(const Complex& lhs,const Complex& rhs)
{
	Complex temp;
	temp.r = lhs.r * rhs.r - lhs.i * rhs.i;
	temp.i = lhs.r * rhs.i + lhs.i * rhs.r;
	return temp;
}
Complex operator !(const Complex& c)
{
	Complex temp;
	temp.r = c.r;
	temp.i = -(c.i);
	return temp;
}
bool operator ==(const Complex& lhs,const Complex& rhs)
{
	return(lhs.r == rhs.r && lhs.i == rhs.i);
}
bool operator !=(const Complex& lhs,const Complex& rhs)
{
	return(lhs.r != rhs.r || lhs.i != rhs.i);
}
istream& operator >>(istream& in,Complex& rhs)
{
	in >> rhs.r >> rhs.i;
	return in;
}
ostream& operator <<(ostream& out,const Complex& rhs)
{
	out << rhs.r;
	if(rhs.i < 0)
	{
		out << rhs.i << "i";
	}
	else{
		out << "+" << rhs.i << "i" ;
	}
	return out;
}

int main(){

    Complex a, b;

    cout <<"input a & b: "<<endl;

    cin >> a >> b;

    cout << "a + b = " << a + b << endl;

    cout << "a - b = " << a - b << endl;

    cout << "a * b = " << a * b << endl;

    cout << "conjugate of a = " << !a << endl;


    if(a==b)

        cout << "a is equal to b." << endl;

    if(a!=b)

        cout << "a is not equal to b." << endl;

        

    return 0;

}
