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

/*
	Inoder traversal of a binary tree
*/
void inorder(struct Node * temp)
{
	if(!temp)
	{
		return;
	}

	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

/*function to insert element in binary tree */
void insert(struct Node* node, int key)
{
    // queue<struct Node*> q;
    // q.push(temp);

    // Do level order traversal until we find
    // an empty place.
    // while (!q.empty()) {
    //     struct Node* temp2 = q.front();
    //     q.pop();

    //     if (!temp2->left) {
    //         temp2->left = newNode(key);
    //         break;
    //     } else
    //         q.push(temp2->left);

    //     if (!temp2->right) {
    //         temp2->right = newNode(key);
    //         break;
    //     } else
    //         q.push(temp2->right);
    // }
	struct Node * curNode = node;
	if(!curNode)
	{
		return;
	}
	while(1)
	{
		if(!curNode->left)
		{
			curNode->left = newNode(key);
			break;
		}
		else
		{
			curNode = curNode->left;
		}

		if(!curNode->right)
		{
			curNode->right = newNode(key);
			break;
		}
		else
		{
			curNode = curNode->right;
		}
	}
}

// Driver code
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before insertion:";
    inorder(root);

    int key = 12;
    insert(root, key);

    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);

    return 0;
}