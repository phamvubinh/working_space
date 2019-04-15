/* The Point class Header file (Point.h) */
#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class Point {
private:
   int x, y; // Private data members

public:
   Point(int x = 0, int y = 0); // Constructor
   int getX() const; // Getters
   int getY() const;
   void setX(int x); // Setters
   void setY(int y);
   friend std::ostream & operator<<(std::ostream & out, const Point & point);
   friend std::istream & operator>>(std::istream & in, Point & point);
};

#endif