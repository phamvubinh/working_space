#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <string>
#include <iostream>
using namespace std;

class Circle
{
private:
	double radius;
	string color;
public:
	Circle(double radius=1.0, string color="red");
	double getRadius() const;
	void setRadius(double radius);
	string getColor() const;
	void setColor(string color);

	void printInfo();
	double getArea() const;
};

#endif




