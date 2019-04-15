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

/* Function to delete the given depest node  */
void deleteDepest(struct Node * root, struct Node * d_node)
{
	queue<struct Node*> q;
	q.push(root);

	/* Do level order traversal util last node */
	struct Node * temp;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp->right)
		{
			if(temp->right == d_node)
			{
				temp->right = NULL;
				delete(d_node);
				return;
			}
			else
			{
				q.push(temp->right);
			}
		}

		if(temp->left)
		{
			if(temp->left == d_node)
			{
				temp->left = NULL;
				delete(d_node);
				return;
			}
			else
			{
				q.push(temp->left);
			}
		}
	}
}

/* Function to delete element in binary tree */
void deletion(struct Node * root, int key)
{
	queue<struct Node *> q;
	q.push(root);

	struct Node *temp;
	struct Node *key_node = NULL;

	/* Do level order traversal to find depest node nad node to be deleted (key_node) */
	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp->key == key)
		{
			key_node = temp;
		}
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
	}

	int x = temp->key;
	deleteDepest(root, temp);
	key_node->key = x;

}

/* Driver code */
int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before deletion : ";
    inorder(root);

    int key = 11;
    deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}