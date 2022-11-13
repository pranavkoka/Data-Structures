#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i = i+1)
    {   
        while (i !=0 && arr[i] < arr[i-1]) 
        {
            swap(&arr[i],&arr[i-1]);
            i = i-1;
        }
    }
    int j;
    for (j = 0; j < n-1; j = j+1)
    {
        printf(" %d,", arr[j]);
    }
    printf(" %d", arr[j]);
    printf("\n");   
}

void getarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n-1; i = i+1)
        {
            printf(" %d,", arr[i]);
        }
    printf(" %d", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {37, 69, 42, 51, 97, 27};
    int n = sizeof(arr)/sizeof(arr[0]);
    getarray(arr, n);
    printf("Sorted array is: \n");
    insertionsort(arr, n);
    return 0;
}