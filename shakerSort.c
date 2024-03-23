#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shakerSort(int arr[], int n) 
{
    int left = 0;
    int right = n - 1;
    bool swapped = true;

    while (left < right && swapped) 
    {
        swapped = false;

        for (int i = left; i < right; i++) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        right--;

        for (int i = right; i > left; i--) 
        {
            if (arr[i] < arr[i - 1]) 
            {
                swap(&arr[i], &arr[i - 1]);
                swapped = true;
            }
        }
        left++;
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

    shakerSort(arr, n);
    printArray(arr, n);

    return 0;
}
