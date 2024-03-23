#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) 
{
    int *output = (int*)malloc((size + 1) * sizeof(int));

    if (output == NULL) 
    {
        printf("Memory allocation failed");
        return;
    }

    int max = array[0];

    for (int i = 1; i < size; i++) 
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int *count = (int*)malloc((max + 1) * sizeof(int));

    if (count == NULL) 
    {
        printf("Memory allocation failed");
        free(output);
        return;
    }

    for (int i = 0; i <= max; ++i) 
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) 
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) 
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }


    for (int i = 0; i < size; i++) 
    {
        array[i] = output[i];
    }

    free(output);
    free(count);
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
    
    countingSort(arr, n);
    printArray(arr, n);

    return 0;
}