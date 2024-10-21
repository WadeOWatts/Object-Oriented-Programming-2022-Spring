#include<iostream>
#include <fstream>
#include <string>

using namespace std;

class Rectangle
{
	public:
		void input(istream& ins);
		void output(ostream& outs);
		int get_area();
	private:
		int width;
		int height;
		int area;
};

class Triangle
{
	public:
		void input(istream& ins);
		void output(ostream& outs);
		int get_area();
	private:
		int base;
		int height;
		int area;
};

ifstream inp;
ofstream oup;

void Rectangle::input(istream& ins)
{
	ins >> width >> height;
	return;
}

int Rectangle::get_area()
{
	area = width * height;
	return area;
}

void Rectangle::output(ostream& outs)
{
	outs << area << endl;
}

void Triangle::input(istream& ins)
{
	ins >> base >> height;
	return;
}

int Triangle::get_area()
{
	area = base * height / 2;
	return area;
}

void Triangle::output(ostream& outs)
{
	outs << area << endl;
}

string name;
char title;

int main()
{
	Rectangle r;
	Triangle t;
	
	int max = 0,temp = 0;
	string maxname;
	
	inp.open("testcase.txt");
	oup.open("output.txt");

	while(!inp.eof())
	{
		inp >> title >> name;
		oup << "The area of " << title << name << " is ";
		if(title == 'T')
		{
			t.input(inp);
			temp = t.get_area();
			t.output(oup);
		}
		else
		{
			r.input(inp);
			temp = r.get_area();
			r.output(oup);
		}
		if(max < temp)
		{
			max = temp;
			maxname = title + name;
		}
	}

	oup << maxname << " has the biggest area : " << max << endl;
	
	inp.close();
	oup.close();

	return 0;
}
