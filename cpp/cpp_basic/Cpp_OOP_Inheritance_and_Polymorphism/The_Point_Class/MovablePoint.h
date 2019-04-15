#ifndef __MOVEABLE_POINT_H__
#define __MOVEABLE_POINT_H__

#include "Point.h"

class MovablePoint : public Point
{
private:
	int xSpeed, ySpeed;
public:
	MovablePoint(int x, int y, int xSpeed = 0, int ySpeed = 0);
	int getXSpeed() const;
	int getYSpeed() const;
	void setXSpeed(int xSpeed);
	void setYSpeed(int ySpeed);
	void move();
	void print() const;
};

#endif