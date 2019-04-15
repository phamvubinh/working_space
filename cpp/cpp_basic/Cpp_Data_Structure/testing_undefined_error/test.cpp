#include <iostream>
#include "test.h"
using namespace std;
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

// https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
// this is a trick to define template in .cpp file
template Stack<int>::Stack(int cap, int inc);
template Stack<double>::Stack(int cap, int inc);

template Stack<int>::~Stack();
template Stack<double>::~Stack();