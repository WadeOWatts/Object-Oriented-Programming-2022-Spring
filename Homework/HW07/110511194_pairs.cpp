#include <iostream>
#include "110511194_pairs.h"
using namespace std;

pairs operator +(const pairs& a,const pairs& b)
{
	pairs temp;
	temp.f = a.f + b.f;
	temp.s = a.s + b.s;
	return temp;
}
pairs operator -(const pairs& a,const pairs& b)
{
	pairs temp;
	temp.f = a.f - b.f;
	temp.s = a.s - b.s;
	return temp;
}
pairs operator *(const pairs& a,const pairs& b)
{
	pairs temp;
	temp.f = a.f * b.f;
	temp.s = a.s * b.f;
	return temp;
}
istream& operator >>(istream& ins, pairs& a)
{
	ins >> a.f >> a.s;
	return ins;

}
ostream& operator <<(ostream& outs,const pairs& a)
{
	outs << "( " << a.f << " , " << a.s << " )";
	return outs;
}
pairs::pairs():f(0),s(0){
	
}
pairs::pairs(int a):f(a),s(0){
	
}
pairs::pairs(int a,int b):f(a),s(b){
	
}
