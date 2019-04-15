#include "iostream"
#include "Time.h"
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[])
{
	Time t1(2, 5, 7);
	t1.print();

	//Object pointer
	Time * ptrT1 = & t1;
	(*ptrT1).print();
	ptrT1->print(); // same as above

	// Object reference
	Time &refT1 = t1;
	refT1.print();

	// Dynamic allocation
	Time * ptrT2 = new Time(4, 5, 6);
	ptrT2->print();
	delete ptrT2;

	// Object Array
	Time tArray1[2];    // tArray1 is an array of Time with 2 elements
	                   // Use default constructor for all elements
	tArray1[0].print();  // 00:00:00
	tArray1[1].print();  // 00:00:00

	Time tArray2[2] = {Time(7, 8, 9), Time(10)}; // Invoke constructor
	tArray2[0].print();  // 07:08:09
	tArray2[1].print();  // 10:00:00

	Time * ptrArray3 = new Time[2] {Time(5, 8, 12), Time(23)};
	ptrArray3[0].print();  // 07:08:09
	ptrArray3[1].print();  // 10:00:00

	ptrArray3->print();
	(ptrArray3+1)->print();

	delete[] ptrArray3;

	return 0;
}