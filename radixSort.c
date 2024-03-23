#include <stdio.h>
#include <stdlib.h>

int getMax(int array[], int n) 
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void countingSort(int array[], int size, int place) 
{
    int *output = (int *)malloc((size + 1) * sizeof(int));

    if (output == NULL) 
    {
        printf("Memory allocation failed");
        return;
    }
    
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++) 
    {
        if (((array[i] / place) % 10) > max)
        max = array[i];
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));

    if (count == NULL) 
    {
        printf("Memory allocation failed");
        free(output);
        return;
    }

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }
        
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) 
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void radixsort(int array[], int size) 
{
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSort(array, size, place);
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
    int arr[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, n);
    printArray(arr, n);

    return 0;
}