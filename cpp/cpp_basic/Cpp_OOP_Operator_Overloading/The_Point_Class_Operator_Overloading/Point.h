/* The Point class Header file (Point.h) */
#ifndef __POINT_H__
#define __POINT_H__

class Point {
private:
   int x, y; // Private data members

public:
   Point(int x = 0, int y = 0); // Constructor
   int getX() const; // Getters
   int getY() const;
   void setX(int x); // Setters
   void setY(int y);
   void print() const;
   const Point operator+(const Point & rhs) const;
         // Overload '+' operator as member function of the class
   const Point &operator-(const Point & rhs);
         // Overload '-' operator as member function of the class
   const Point &operator*(const Point & rhs);
};

#endif