#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i = i+1)
    {    
        min = i;
        for (j = i+1; j < n+1; j = j+1)
        {
            if (arr[j] < arr[min])
                min = j;
        
            swap(&arr[min],&arr[i]);
        }
        printf(" %d,", arr[min]);
    }
    printf(" %d", arr[i]);
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
    selectionsort(arr, n);
    return 0;
}