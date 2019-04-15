#ifndef __STACK_H__
#define __STACK_H__
/*
	Note the the template function should be difined in .h file also
	https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
*/
#include <iostream>
using namespace std;

// Forward Reference
template <typename T>
class Stack;
template <typename T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & s);

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
	void push(const T & value);
	bool pop(T & value);
	bool isEmpty() const;
	bool isFull() const;
friend std::ostream & operator<< <>(std::ostream & os, const Stack<T> & s);   // <> is the casting type
};

// construtor - create an empty stack
template <typename T>
Stack<T>::Stack(int cap, int inc) : capacity(cap), increment(inc)
{
	data = new T[capacity];
	topOfStack  = -1;
}

// destructor - remove all dynamically allocated data
template <typename T>
Stack<T>::~Stack()
{
	delete[] data; // remove the dynamically allocate storage
}

// isEmpty - check the value of topOfStack
template <typename T>
bool Stack<T>::isFull()const
{
	return (topOfStack >= capacity - 1);
}

// isEmpty - check the value of topOfStack
template <typename T>
bool Stack<T>::isEmpty() const
{
	return (topOfStack < 0);
}

// push value into stack
template <typename T>
void Stack<T>::push(const T & value)
{
	if(isFull())
	{
		// increase the capacity
		capacity += increment;
		// allocate bigger array and copy the old data
		T * newDataPtr = new T[capacity];
		for (int i = 0; i <= topOfStack; ++i)
		{
			newDataPtr[i] = data[i];
		}
		// add the new data into stack
		newDataPtr[++topOfStack] = value;
		// remove old data pointer and point to newDataPtr location
		delete[] data;
		data = newDataPtr;

		cout << "Stack is full, increased the cap to: " << capacity << endl;
	}
	else
	{
		topOfStack++;
		data[topOfStack] = value;
	}
}

// push value into stack
template <typename T>
bool Stack<T>::pop(T & value)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		topOfStack--;
		value = data[topOfStack];
		return true;
	}
}

// overload the stream insertion operator to print the list
template <typename T>
std::ostream & operator<< (std::ostream & os, const Stack<T> & stack)
{
	os << "{";
	for (int i = 0; i <= stack.topOfStack; ++i)
	{
		os << stack.data[i];
		if (i <= stack.topOfStack - 1)
		{
			os << ", ";
		}
	}
	os << "}";
}

#endif