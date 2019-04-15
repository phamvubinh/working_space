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

// public Functions
void Point::print() const {
	cout << "(" << x << "," << y << ")" << endl;
}

const Point Point::operator+(const Point & rhs) const {
	return Point(x + rhs.x, y + rhs.y);
}

const Point & Point::operator-(const Point & rhs){
	x += rhs.x;
	y += rhs.y;
	return * this;
}

const Point &Point::operator*(const Point & rhs){
	return Point(x*rhs.x, y*rhs.y);
}