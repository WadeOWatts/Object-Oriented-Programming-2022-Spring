#ifndef PAIRS_H
#define PAIRS_H
#include <iostream>
using namespace std;

class pairs
{
	public:
		friend pairs operator +(const pairs& a,const pairs& b);
		friend pairs operator -(const pairs& a,const pairs& b);
		friend pairs operator *(const pairs& a,const pairs& b);
		friend istream& operator >>(istream& ins, pairs& a);
		friend ostream& operator <<(ostream& outs,const pairs& a);
		pairs();
		pairs(int);
		pairs(int,int);
	private:
		int f;
		int s;
};

#endif