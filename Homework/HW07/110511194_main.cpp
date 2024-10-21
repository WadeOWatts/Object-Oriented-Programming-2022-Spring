#include <iostream>
#include "110511194_pairs.h"
using namespace std;

int main()
{
	pairs a,b;
	cout << "Numbers: ";
	cin >> a >> b;
	cout << "(a,b) + (c,d) = " << a + b << endl;
	cout << "(a,b) - (c,d) = " << a - b << endl;
	cout << "(a,b) * c = " << a * b << endl;
	return 0;
}
