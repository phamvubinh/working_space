#ifndef __NODE_H__
#define __NODE_H__

template <typename T> class List;
template <class T>
class Node
{
private:
	T data;
	Node *nextPtr;
public:
	Node(T d): data(d), nextPtr(0) {}; // constructor
	T getData() const { return data; }; // public getter for data
	Node * getNextPtr() const { return nextPtr; } // public getter for nextPtr

friend class List<T>; // Make List class a friend to access private data
};

#endif