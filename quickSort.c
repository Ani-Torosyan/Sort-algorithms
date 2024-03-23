#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) 
{
    int position = array[high];
    
    int i = (low - 1);

    for (int j = low; j < high; j++) 
    {
        if (array[j] <= position) 
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        int pos = partition(array, low, high);
        quickSort(array, low, pos - 1);
        quickSort(array, pos + 1, high);
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

    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}