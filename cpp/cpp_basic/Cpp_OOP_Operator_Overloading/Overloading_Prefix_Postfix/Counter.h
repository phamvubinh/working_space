#ifndef __COUNTER_H__
#define __COUNTER_H__
#include <iostream>

class Counter
{
private:
	int count;
public:
	Counter(int count=0) : count(count){};
	int getCount() const { return count; }
	void setCount(int count) { this->count = count; }

	Counter & operator++();   				// ++prefix
	const Counter operator++(int dummy); 	// postfix++

	friend std::ostream & operator<<(std::ostream & out, const Counter & counter);
};

#endif