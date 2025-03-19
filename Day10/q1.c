#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int *arr;
    int start;
    int end;
    int sum;
} Threadargs;

void *calculate_sum(void *args)
{
    Threadargs *data = (Threadargs *)args;
    data->sum = 0;
    for (int i = data->start; i < data->end; i++)
    {
        data->sum += data->arr[i];
    }
    return NULL;
}

int main()
{
    printf("Day 9 - Question 1: Add different halfs of an array using multiple threads. \n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");
    int n;

    printf("Enter the size of the array:");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d elements:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    pthread_t thread1, thread2;
    Threadargs args1, args2;

    args1.arr = arr;
    args1.start = 0;
    args1.end = n / 2;

    args2.arr = arr;
    args2.start = n / 2;
    args2.end = n;

    args1.sum = 0;
    args2.sum = 0;

    pthread_create(&thread1, NULL, calculate_sum, (void *)&args1);
    pthread_create(&thread2, NULL, calculate_sum, (void *)&args2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Sum of first half: %d\n", args1.sum);
    printf("Sum of second half: %d\n", args2.sum);
    printf("Total sum: %d\n", args1.sum + args2.sum);

    free(arr);
    return 0;
}