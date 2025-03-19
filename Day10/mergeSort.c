/*
Merge Sort using multiple threads.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int *arr;
    int start;
    int end;
} Threadargs;

void merge(int *arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int *left = (int *)malloc(n1 * sizeof(int));
    int *right = (int *)malloc(n2 * sizeof(int));

    if (!left || !right)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void *mergeSortThread(void *args)
{
    Threadargs *data = (Threadargs *)args;
    mergeSort(data->arr, data->start, data->end);
    return NULL;
}

int main()
{
    printf("Day 9 - Question 2: Merge Sort using multiple threads in C. \n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (!arr)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    if (n == 1)
    {
        printf("Sorted array: %d\n", arr[0]);
        free(arr);
        return 0;
    }

    pthread_t thread1, thread2;
    Threadargs args1, args2;

    args1.arr = arr;
    args1.start = 0;
    args1.end = n / 2 - 1;

    args2.arr = arr;
    args2.start = n / 2;
    args2.end = n - 1;

    pthread_create(&thread1, NULL, mergeSortThread, (void *)&args1);
    pthread_create(&thread2, NULL, mergeSortThread, (void *)&args2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    merge(arr, 0, n / 2 - 1, n - 1);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
