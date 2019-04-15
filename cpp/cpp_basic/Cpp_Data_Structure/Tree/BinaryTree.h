#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>
#include <queue>
#include "Node.h"

using namespace std;

// forward reference
template <typename T>
ostream &  operator<< (ostream & os, const BinaryTree<T> & tree);

template <typename T>
class BinaryTree
{
private:
	Node<T> * rootPtr;

	// private help function
	void insertNode(Node<T> * & ptr, const T & value);
	void preOrderSubTree(const Node<T> * ptr, std::ostream & os = std::cout) const;
	void inOrderSubTree(const Node<T> * ptr, std::ostream & os = std::cout) const;
	void postOrderSubTree(const Node<T> * ptr, std::ostream & os = std::cout) const;
	void removeSubTree(Node<T> * & ptr);
public:
	BinaryTree();
   ~BinaryTree();  // Destructor
	void insert(const T & value);
	bool isEmpty() const;
	void preOrderTraversal(std::ostream & os = std::cout) const;
	void inOrderTraversal(std::ostream & os = std::cout) const;
	void postOrderTraversal(std::ostream & os = std::cout) const;
	void breadthFirstTraversal(std::ostream & os = std::cout) const;

friend std::ostream & operator<< <>(std::ostream & os, const BinaryTree<T> & lst);
};

// constructor - create a tree with only root
template <typename T>
BinaryTree<T>::BinaryTree() : rootPtr(0) {}

// destructor - remove subtree from node
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	removeSubTree(rootPtr);
}

template <typename T>
void BinaryTree<T>::removeSubTree(Node<T> * & ptr) {
   if (ptr) {
      removeSubTree(ptr->leftPtr);   // remove left subtree
      removeSubTree(ptr->rightPtr);  // remove right subtree
      delete ptr;
   }
}


template <typename T>
bool BinaryTree<T>::isEmpty() const { return rootPtr == 0; }

// Push the data in front by dynamically allocate a new node
template <typename T>
void BinaryTree<T>::insert(const T & value)
{
	insertNode(rootPtr, value);
}
// Push the data in front by dynamically allocate a new node
template <typename T>
void BinaryTree<T>::insertNode(Node<T> * & ptr, const T & value)
{
	if(ptr == 0)
	{
		ptr = new Node<T>(value);
	}
	else
	{
		if(value < ptr->data)
		{
			insertNode(ptr->leftPtr, value);
		}
		else if(value > ptr->data)
		{
			insertNode(ptr->rightPtr, value);
		}
		else
		{
			std::cout << "dupicate value" << std::endl;
		}
	}
}

template <typename T>
void BinaryTree<T>::preOrderTraversal(ostream & os) const
{
	os << "{";
	preOrderSubTree(rootPtr);
	os << "}" << endl;
}

template <typename T>
void BinaryTree<T>::preOrderSubTree(const Node<T> * ptr, std::ostream & os) const
{
	if (ptr)
	{
		os << ptr->data << ' ';
		preOrderSubTree(ptr->leftPtr);
		preOrderSubTree(ptr->rightPtr);
	}
}

template <typename T>
void BinaryTree<T>::inOrderTraversal(ostream & os) const
{
	os << "{";
	inOrderSubTree(rootPtr);
	os << "}" << endl;
}

template <typename T>
void BinaryTree<T>::inOrderSubTree(const Node<T> * ptr, ostream & os) const
{
	if (ptr)
	{
		preOrderSubTree(ptr->leftPtr);
		os << ptr->data << ' ';
		preOrderSubTree(ptr->rightPtr);
	}
}

template <typename T>
void BinaryTree<T>::postOrderTraversal(ostream & os) const
{
	os << "{";
	postOrderSubTree(rootPtr);
	os << "}" << endl;
}

template <typename T>
void BinaryTree<T>::postOrderSubTree(const Node<T> * ptr, ostream & os) const
{
	if (ptr)
	{
		preOrderSubTree(ptr->leftPtr);
		preOrderSubTree(ptr->rightPtr);
		os << ptr->data << ' ';
	}
}

// Breadth first search (BFS)
template <typename T>
void BinaryTree<T>::breadthFirstTraversal(ostream & os) const
{
	std::queue<Node<T> * > q;
	if(!isEmpty())
	{
		q.push(rootPtr);
	}

	os << "{";
	Node<T> * currentPtr = q.front();
	while (currentPtr)
	{
		std::cout << currentPtr->data << ' ';
		if (currentPtr->leftPtr) q.push(currentPtr->leftPtr);
		if (currentPtr->rightPtr) q.push(currentPtr->rightPtr);
		q.pop();  // remove this node
		currentPtr = q.front();
	}
	os << '}' << std::endl;
}

// Overload the stream insertion operator to print the list in in-order traversal
template <typename T>
std::ostream & operator << (std::ostream & os, const BinaryTree<T> & tree)
{
	tree.inOrderTraversal(os);
	return os;
}
#endif