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

NodeAddress* insert(NodeAddress* node, int item)
{
	if (node==NULL) return (createnode(item));
	if (item<node->value)
	{
		node->left = insert(node->left, item);
	}
	else if (item>node->value)
	{
		node->right = insert(node->right, item);
	}
	//return newnode;

	node->height = max(getHeight(node->left),getHeight(node->right)) + 1;
	int bf = getBF(node);

	//LL
	if (bf > 1 && item < node->left->value)
	{
		return RR(node);
	}

	//RR
	if (bf < -1 && item > node->right->value)
	{
		return LR(node);
	}

	//LR
	if (bf > 1 && item > node->left->value)
	{
		node->left = LR(node->left);
		return RR(node);
	}

	//RL
	if (bf < -1 && item < node->right->value)
	{
		node->right = RR(node->right);
		return LR(node);
	}
	return node;
}

NodeAddress* minValueNode(NodeAddress* node)
{
	NodeAddress* current = node;
	while(current->left!=NULL)
		current = current->left;
	return current;
}

NodeAddress* delete(NodeAddress* root, int item)
{
	if (root==NULL)
		return root;
	if(item<root->value)
		root->left=delete(root->left,item);
	else if(item>root->value)
		root->right=delete(root->right,item);
	else
	{
		if((root->left==NULL) || (root->right==NULL))
		{
			NodeAddress* temp = root->left ? root->left : root->right;
			if (temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			NodeAddress* temp = minValueNode(root->right);
			root->value=temp->value;
			root->right=delete(root->right,temp->value);
		}
	}
	if (root==NULL)
		return root;
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
	int bf=getBF(root);
	if(bf>1 && getBF(root->left)>=0)
		return RR(root);
	if(bf<-1 && getBF(root->right)<=0)
		return LR(root);
	if(bf>1 && getBF(root->left)<0)
	{
		root->left=LR(root->left);
		return RR(root);
	}
	if(bf<-1 && getBF(root->right)>0)
	{
		root->right=RR(root->right);
		return LR(root);
	}
	return root;
}

void inorder(NodeAddress* root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->value);
		inorder(root->right);
	}
}
 
int main()
{
	NodeAddress* root = NULL;
	root = insert(root, 7);
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 12);
	//root = insert(root, 7);
	root = insert(root, 6);
	//root = insert(root, 2);
	//root = insert(root, 1);
	//root = insert(root, 6);
	root = insert(root, 9);
	inorder(root);
	printf("\n");
	root = delete(root,6);
	inorder(root); 
	printf("\n");
	root = delete(root,1);
	inorder(root); 
	printf("\n");

	return 0;
}