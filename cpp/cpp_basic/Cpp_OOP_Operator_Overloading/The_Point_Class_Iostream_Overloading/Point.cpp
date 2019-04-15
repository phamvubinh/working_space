#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x, int y) : x(x), y(y) { } // using initializer list

// getters
int Point::getX() const { return x; }
int Point::getY() const { return y; }

// setters
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

ostream & operator<<(ostream & out, const Point & point)
{
	out << "(" << point.x << "," << point.y << ")"; //access private dae
	return out;
}

istream & operator>>(istream & in, Point & point)
{
	cout << "Enter x and y cood: ";
	in >> point.x >> point.y;    // access private data
	return in;
}