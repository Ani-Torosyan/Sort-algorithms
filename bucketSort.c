#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    float data;
    struct Node* next;
};

struct Node* createNode(float value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, float value) 
{
    struct Node* newNode = createNode(value);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertionSort(struct Node** head) 
{
    if (*head == NULL || (*head)->next == NULL) 
    {
        return;
    }

    struct Node *sorted = NULL;
    struct Node *current = *head;
    while (current != NULL) 
    {
        struct Node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data) 
        {
            current->next = sorted;
            sorted = current;
        } 
        else 
        {
            struct Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) 
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

void bucketSort(float arr[], int n) 
{
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));

    if (buckets == NULL) 
    {
        printf("Memory allocation failed");
        return;
    }

    for (int i = 0; i < n; i++) 
    {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) 
    {
        int bucketIndex = n * arr[i];
        insertNode(&buckets[bucketIndex], arr[i]);
    }

    for (int i = 0; i < n; i++) 
    {
        insertionSort(&buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) 
    {
        struct Node* current = buckets[i];
        while (current != NULL) 
        {
            arr[index++] = current->data;
            current = current->next;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        free(buckets[i]);
    }
    free(buckets);
}

void printArray(float arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%.1f ", arr[i]);
    }
}

int main() 
{
    float arr[] = {0.5, 0.4, 0.3, 0.2, 0.1};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}
