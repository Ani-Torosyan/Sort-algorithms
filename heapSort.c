#include <stdio.h>
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }
 
    if (right < N && arr[right] > arr[largest])
    { 
        largest = right;
    }
 
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
 
void heapSort(int arr[], int N)
{
 
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    for (int i = N - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
 
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}
