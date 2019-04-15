#include "Point.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Point p1(1,2), p2;

	// using overload operator <<
	cout << p1 << endl;  // support cascading
	operator<<(cout,p1);
	cout << endl;

	// using overload operator >>
	cin >> p1;
	cout << p1 << endl;
	operator>>(cin,p1);
	cout << p1 << endl;
	cin >> p1 >> p2;

	cout << p1 << endl;
	cout << p2 << endl;
	return 0;
}