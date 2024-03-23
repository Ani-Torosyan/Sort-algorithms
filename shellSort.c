#include <stdio.h>

void shellSort(int arr[], int n) 
{
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
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

    shellSort(arr, n);
    printArray(arr, n);

    return 0;
}
