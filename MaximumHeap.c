#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int* y)
{
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void heapify(int *a, int n, int i)
{
	int biggest = i;
	int lc = 2*i + 1;
	int rc = 2*i + 2;
	if (lc < n && a[lc] > a[biggest])
	{
		biggest = lc;
	}
	if (rc < n && a[rc] > a[biggest])
	{
		biggest = rc;
	}
	if (biggest != i)
	{
		swap(&a[i], &a[biggest]);
		heapify(a, n, biggest);
	}
}

void buildheap(int *a, int n)
{
	int last = (n/2) -1;
	for (int i = last; i >=0; i = i - 1)
	{
		heapify(a, n, i);
	}
}

int max(int x, int y)
{
	if (x > y) {return x;}
	else if (y > x) {return y;}
}

void show(int *a, int n)
{
	int i;
	for (i = 0; i < n; i = i + 1)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int arr[] = {4,18,17,10,19,20,14,8,3,12,24,31,28,7,13};
	int*x = arr;
	int n = sizeof(arr)/sizeof(arr[0]);
	buildheap(x,n);
	show(x,n);
	return 0;
}