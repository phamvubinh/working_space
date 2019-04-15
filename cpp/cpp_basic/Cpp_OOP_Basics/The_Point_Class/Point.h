#ifndef __POINT_H__
#define __POINT_H__

class Point
{
private:
	int x;
	int y;
public:
	Point(int x=0, int y=0);
	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	void setXY(int x, int y);
	double getMagnitude() const;
	double getArgument() const;

	void print() const;
};

#endif