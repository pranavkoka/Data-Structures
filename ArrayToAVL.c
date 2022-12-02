#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* left;
	struct Node* right;
	int height;
} NodeAddress;

int getHeight(NodeAddress* n)
{
	if (n==NULL)
		return 0;
	return n->height;
}

NodeAddress* createnode(int item)
{
	NodeAddress* newnode = (NodeAddress*) malloc(sizeof(NodeAddress));
	newnode->value = item;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;
	return newnode;
}

int max(int x, int y)
{
	if (x > y) {return x;}
	else if (y > x) {return y;}
}

int getBF(NodeAddress* n)
{
	if (n==NULL)
	{
		return 0;
	}
	return (getHeight(n->left) - getHeight(n->right));
}

NodeAddress* RR(NodeAddress* y)
{
	NodeAddress* x = y->left;
	NodeAddress* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	return x;
}

NodeAddress* LR(NodeAddress* x)
{
	NodeAddress* y = x->right;
	NodeAddress* T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
	return y;
}

void show (NodeAddress* root)
{
	if (root !=NULL)
	{
		show(root->left);
		printf("%d ", root->value);
		show(root->right);
	}
}

NodeAddress* insert(NodeAddress* root, int item)
{
	if (root==NULL) return createnode(item);
	if (item<root->value)
	{
		root->left = insert(root->left, item);
	}
	else if (item>root->value)
	{
		root->right = insert(root->right,item);
	}
	//return root;

	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	int bf = getBF(root);

	//LL
	if (bf > 1 && item < root->left->value)
	{
		return RR(root);
	}

	//RR
	if (bf < -1 && item > root->right->value)
	{
		return LR(root);
	}

	//LR
	if (bf > 1 && item > root->left->value)
	{
		root->left = LR(root->left);
		return RR(root);
	}

	//RL
	if (bf < -1 && item < root->right->value)
	{
		root->right = RR(root->right);
		return RR(root);
	}
	return root;
}

NodeAddress* arrayToBST (int *a, int n)
{
	NodeAddress* root = NULL;
	int i;
	root = insert(root,a[0]);
	for (i = 1; i < n; i = i + 1)
	{
		insert(root, a[i]);
	}
	return root;
}

int main()
{
	int array[] = {1,2,4,5,6,3};
	int* x = array;
	int n = sizeof(array)/sizeof(array[0]);
	NodeAddress* linkedlist = arrayToBST(x,n);
	show(arrayToBST(x,n));
	return 0;
}