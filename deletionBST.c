#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} NodeAddress;

NodeAddress* createnode(int item)
{
    NodeAddress* newnode = (NodeAddress*) malloc(sizeof(NodeAddress));
    newnode->value = item;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
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
    return root;
}

NodeAddress* arrayToReverseBST (int *a, int n)
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

NodeAddress* minValueNode(NodeAddress* node)
{
    NodeAddress* current = node;
    while (current && current->left != NULL)
        current = current->left;  
    return current;
}

NodeAddress* deleteNode(NodeAddress* root, int item)
{
    if (root == NULL)
        return root;
    if (item < root->value)
        root->left = deleteNode(root->left, item);
    else if (item > root->value)
        root->right = deleteNode(root->right, item);
    else 
    {
        if (root->left == NULL) 
        {
            NodeAddress* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            NodeAddress* temp = root->left;
            free(root);
            return temp;
        }
        NodeAddress* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int main()
{
    int array[] = {40,2,9,13,17,69,42,57,60,27,1,7,11,70,41};
    int* x = array;
    int n = sizeof(array)/sizeof(array[0]);
    NodeAddress* BST = arrayToReverseBST(x,n);
    show(BST);
    NodeAddress* deleted = deleteNode(BST,42);
    printf("\n");
    show(deleted);
    return 0;
}