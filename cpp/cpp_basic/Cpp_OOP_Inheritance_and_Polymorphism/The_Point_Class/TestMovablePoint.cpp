#include <iostream>
#include "MovablePoint.h"
#include "typeinfo"    // need for typeid operator
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "-------------------------------------" << endl;
	cout << "Checking basic inheritance" << endl;
	// Super class test
	Point p1(4, 5);
	p1.print();
	cout << endl;

	// Derived class
	MovablePoint mp1(11, 22);  // subclass default speed
	mp1.print();
	cout << endl;

	mp1.setXSpeed(8);
	mp1.setYSpeed(10);
	mp1.move();
	mp1.print();
	cout << endl;

	// Derived class
	MovablePoint mp2(11, 22, 33, 44);
	mp2.print();  // MovablePoint @ (11,22) Speed=(33,44)
	cout << endl;
	mp2.move();
	mp2.print();  // MovablePoint @ (44,66) Speed=(33,44)
	cout << endl;

	cout << "-------------------------------------" << endl;
	cout << "Checking polymorphism and virtual function" << endl;

	// need to use pointer or referance for the subclass overide function using
	Point * ptrP1 = new MovablePoint(1, 2, 11, 12); // upcast
	ptrP1->print();  // Runsubclass version
	cout << endl;
	delete ptrP1;

	// Using Object Reference
	MovablePoint mp3(21, 22, 23, 24);
	Point & p2 = mp3;  // upcast from Point to movable point
	p2.print();     // MovablePoint @ (21,22) Speed=(23,24)
                   //   - Run subclass version!!
    cout << endl;

	// Using object with explicit constructor
	Point p3 = MovablePoint(31, 32, 33, 34);  // upcast
	p3.print();     // Point @ (31,32) - Run superclass version!!
	cout << endl;

	cout << "-------------------------------------" << endl;
	cout << "Test up and down casting" << endl;

	// Object pointer
	Point * ptrP3 = new MovablePoint(11, 12, 12, 34);
	// Upcast is always permisable and safe
	ptrP1->print();
	cout << endl;

	// MovablePoint * ptrMP1 = ptrP1; //error when downcast without explicity casting operator
	MovablePoint * ptrMP1 = (MovablePoint *) ptrP3;
	ptrMP1->print();
	cout << endl;
	delete ptrP1;

	cout << "-------------------------------------" << endl;
	cout << "Dynamic cast and typeid" << endl;

	Point * ptrP4 = new MovablePoint(11, 12, 12, 34);
	// Upcast is always permisable and safe
	ptrP1->print();
	cout << endl;

	MovablePoint * ptrMP2 = dynamic_cast<MovablePoint *>(ptrP3); // return null if the cast failed

	//cout << typeid(*ptrP3).name() << endl;
	cout << typeid(*ptrMP2).name() << endl; // the number infront of type-id name is

	cout << typeid(p3).name() << endl;
	return 0;
}