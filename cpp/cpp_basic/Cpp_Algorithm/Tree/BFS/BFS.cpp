// C++ program to insert element in binary tree
#include <iostream>
#include <queue>
using namespace std;

/*
	A binary tree node has key, a pointer to left child and a pointer to right child
*/

struct Node
{
	int key;
	struct Node * left;
	struct Node * right;
};

/*
	Function to create a new node of tree and return pointer
*/
struct Node * newNode(int key)
{
	struct Node * temp = new Node;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Level order tree traversal */
void BFS(struct Node * root)
{
	queue<struct Node *> q;
	q.push(root);

	/* Queu is first in fist our struct */
	struct Node * temp;

	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp->key << " ";

		if(temp->left)
		{
			q.push(temp->left);
		}

		if(temp->right)
		{
			q.push(temp->right);
		}
	}
	cout << endl;
}

/* Driver code */
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    BFS(root);

    return 0;
}