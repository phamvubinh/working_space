#include <iostream>
#include "MovablePoint.h"

using namespace std;

// call constructor of base class to init
MovablePoint::MovablePoint(int x, int y, int xSpeed, int ySpeed)
      : Point(x, y), xSpeed(xSpeed), ySpeed(ySpeed) { }

// Getters
int MovablePoint::getXSpeed() const { return xSpeed; }
int MovablePoint::getYSpeed() const { return ySpeed; }

// Setters
void MovablePoint::setXSpeed(int xs) { xSpeed = xs; }
void MovablePoint::setYSpeed(int ys) { ySpeed = ys; }

// Function
void MovablePoint::print() const
{
	cout << "Moveable";
	Point::print();
	cout << "Speed=" << "(" << xSpeed << "," << ySpeed << ")";
}

void MovablePoint::move()
{
	// subclass cannot access private member of the super class directly
	// need to go through the public interface
#if 0
	Point::setX(Point::getX() + xSpeed);
	Point::setY(Point::getY() + ySpeed);
#else
	// or another way to access the protected data member or attribute
	x += xSpeed;
	y += ySpeed;
#endif
}