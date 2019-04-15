#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>
#include "Node.h"

// Forward Reference
template <typename T>
std::ostream & operator<<(std::ostream & os, const List<T> & lst);

template <typename T>
class List
{
private:
	Node<T> * frontPtr; // First node
	Node<T> * backPtr;  // Last node
public:
	List();
	~List();

	void pushFront(const T & value);
	void pushBack(const T & value);
	bool popFront(T & value);
	bool popBack(T & value);
	bool isEmpty() const;

friend std::ostream & operator<< <>(std::ostream & os, const List<T> & list);
// Overload the stream insertion operator to print the list
};


// Constructor - Create an empty list without any node
template <typename T>
List<T>::List() : frontPtr(0), backPtr(0) {}

// Destrutor - Remove all the dynamically allocated nodes
template <typename T>
List<T>::~List()
{
	while(frontPtr)
	{
		Node<T> * tempPtr = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete tempPtr;
	}
}

// Is list empty, check the frontPtr is NULL
template <typename T>
bool List<T>::isEmpty() const // will not change the value of variable in function
{
	return (frontPtr == 0);
}

// Push the data in front by dynamically allocate a new node
template <typename T>
void List<T>::pushFront(const T & value)
{
	Node<T> *newNodePtr = new Node<T>(value);
	if(isEmpty())
	{
		frontPtr = backPtr = newNodePtr;
	}
	else
	{
		newNodePtr->nextPtr = frontPtr;
		frontPtr = newNodePtr;
	}
}

// Push the data at the end by dynamically allocate a new node
template <typename T>
void List<T>::pushBack(const T & value)
{
	Node<T> * newNodePtr = new Node<T>(value);
	if(isEmpty())
	{
		frontPtr = backPtr = newNodePtr;
	}
	else
	{
		backPtr->nextPtr = newNodePtr;
		backPtr = newNodePtr;
	}
}

// Pop the data in front to value and remove the node
template <typename T>
bool List<T>::popFront(T & value)
{
	if(isEmpty())
	{
		return false;
	}
	else if (frontPtr == backPtr)   // has only one node, need to remove both front and back ptr
	{
		// get the value from front pointer
		value = frontPtr->data;
		//remove front pointer and back pointer
		Node<T> * tempPtr = frontPtr;
		delete tempPtr;
		frontPtr = backPtr = 0;
	}
	else
	{
		// get the value from front pointer
		value = frontPtr->data;
		//remove front pointer
		Node<T> * tempPtr = frontPtr;
		frontPtr = frontPtr->nextPtr;
		delete tempPtr;
	}
	return true;
}

// Pop the data at the end to value and remove the node
template <typename T>
bool List<T>::popBack(T & value)
{
	if(isEmpty())
	{
		return false;
	}
	else if (frontPtr == backPtr)  // only one node
	{
		value = backPtr->data;
		delete backPtr;
		frontPtr = backPtr = 0;
	}
	else
	{
		// locate the second to last node
		Node<T> * currentNodePtr = frontPtr;
		while(currentNodePtr->nextPtr != backPtr)
		{
			currentNodePtr = currentNodePtr->nextPtr;
		}

		value = backPtr->data;
		delete backPtr;
		backPtr = currentNodePtr;
		backPtr->nextPtr = 0;
	}
	return true;
}

// Overload the stream insertion operator to print the list
template <typename T>
std::ostream & operator<<(std::ostream & os, const List<T> & list)
{
	os << "{";
	if(!list.isEmpty())
	{
		Node<T> * currentNodePtr = list.frontPtr;
		while(currentNodePtr)
		{
			os << currentNodePtr->getData();
			if(currentNodePtr != list.backPtr)
			{
				os << ",";
			}
			currentNodePtr = currentNodePtr->getNextPtr();
		}
	}
	os << "}";
}
#endif