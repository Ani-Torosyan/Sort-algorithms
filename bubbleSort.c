#include <stdbool.h>
#include <stdio.h>
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 
        if (swapped == false)
        {
            break;
        }
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

    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}