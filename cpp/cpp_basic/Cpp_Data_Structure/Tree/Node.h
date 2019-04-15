/*
	Node template class for binary tree (Node.h)
*/
#ifndef __NODE_H__
#define __NODE_H__

// forward reference
template <typename T> class BinaryTree;

template <typename T>
class Node
{
private:
	T data;
	Node * rightPtr;
	Node * leftPtr;
public:
	Node(T d): data(d), rightPtr(0), leftPtr(0) {};
	T getData() const { return data; };

friend class BinaryTree<T>;
	// make BinaryTree Class a friend to access private data
};
#endif