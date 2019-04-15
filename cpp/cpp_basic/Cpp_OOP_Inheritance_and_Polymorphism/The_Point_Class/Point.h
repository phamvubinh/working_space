/* The Point class Header file (Point.h) */
#ifndef __POINT_H__
#define __POINT_H__

class Point {
protected:
   int x, y;  // Private data members

public:
   // function's implementation inside the class decleration are automatically treated as inline function
   Point(int x = 0, int y = 0); // Constructor with default arguments
   int getX() const;  // Getter
   void setX(int x);  // Setter
   int getY() const;
   void setY(int y);
   void setXY(int x, int y);

   // change to polymorphism, then the subclass function can overide the method on super class
   virtual void print() const;
};

#endif