#include "Counter.h"
#include <iostream>
using namespace std;


Counter & Counter::operator++()
{
	++count;
	return * this;
}

const Counter Counter::operator++(int dummy)
{
	Counter old(*this);
	++count;
	return old;
}

// overload stream insertion << operator
ostream & operator<<(ostream & out, const Counter & counter)
{
	out << counter.count;
	return out;
}