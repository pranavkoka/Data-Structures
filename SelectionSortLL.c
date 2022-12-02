#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* link;
};

void insert (struct Node** head, int item)
{
	struct Node* toInsert;
	struct Node* ptr;
	toInsert = (struct Node*) malloc(sizeof(struct Node));
	toInsert->value = item;
	toInsert->link = NULL;
	if (*head == NULL)
	{
		*head = toInsert;
	}
	else
	{
		ptr = *head;
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = toInsert;
	}
}

void show (struct Node* head)
{
	while(head!=NULL)
	{
		if (head->link!=NULL)
		{
			printf("%d->", head->value);
			head = head->link;
		}
		else
		{
			printf("%d", head->value);
			head = head->link;
		}
	}
}

struct Node* arrayToLL (int *a, int n)
{
	struct Node* head = NULL;
	int i;
	for (i = 0; i < n; i = i + 1)
	{
		insert(&head, a[i]);
	}
return head;
}

void swap(struct Node* x, struct Node* y)
{
	int temp = x->value;
	x->value = y->value;
	y->value = temp;
}

void selectionsort (int *a, int n)
{
	struct Node* head = arrayToLL(a,n);
	while(head != NULL)
	{
		struct Node* temp = head->link;
		while (temp != NULL)
		{
			if (head->value > temp->value)
			{
				swap(head, temp);
			}
			temp = temp->link;
		}
		printf("%d->",temp->value);
		head = head->link;
	}
}

int main()
{
	int array[] = {4,7,2,9,13,17};
	int* x = array;
	int n = sizeof(array)/sizeof(array[0]);
	//struct Node* linkedlist = arrayToLL(x,n);
	show(arrayToLL(x,n));
	selectionsort(x,n);
	return 0;
}