#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	T * data;  		// array
	int topOfStack; // top of stack start at -1
	int capacity; 	// capacity of the array
	int increment; 	// each subsequent increment size
public:
	explicit Stack(int capacity = 10, int increment = 10);    // explicit to require constructor call avoid abstract casting
	~Stack();  // Destructor
};

#endif