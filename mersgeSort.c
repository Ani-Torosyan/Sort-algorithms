#include <stdio.h>
#include <stdlib.h>
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int *L = (int*)malloc(n1 * sizeof(int));

    if (L == NULL) 
    {
        printf("Memory allocation failed");
        return;
    }

    int *R = (int*)malloc(n2 * sizeof(int));

    if (R == NULL) 
    {
        printf("Memory allocation failed");
        free(L);
        return;
    }
 
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
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
 
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}