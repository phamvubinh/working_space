#include <iostream>
#include <iomanip>
#include "Point.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Point p1(2,4);
	cout << "p1 coordinate: ";
	p1.print();

	cout << fixed << setprecision(2); // set the precision of number after the . in float number
	cout << "mag = " << p1.getMagnitude() << endl;
	cout << "arg = " << p1.getArgument() << endl;

	p1.setX(6);
	p1.setY(8);
	p1.print();

	p1.setXY(1, 2);
	p1.print();

	return 0;
}
