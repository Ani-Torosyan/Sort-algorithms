#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) 
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) 
    {
        minIndex = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        swap(&arr[minIndex], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main() 
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}
