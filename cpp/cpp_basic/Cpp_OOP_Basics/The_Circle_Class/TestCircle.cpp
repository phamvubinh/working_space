#include <iostream>
#include "Circle.h"

int main()
{
	Circle c1(1.2, "red");
	c1.printInfo();

	Circle c2(c1);
	c2.printInfo();

	c2.setColor("blue");
	c2.printInfo();

	return 0;
}