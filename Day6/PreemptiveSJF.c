#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int id, execution_time, arrival_time, remaining_time;
    struct node *next;
};

struct node *create()
{
    struct node *start = NULL;
    int n, id, exec, arrival;
    printf("Enter the total number of processes = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the process id = ");
        scanf("%d", &id);
        printf("Enter the execution time = ");
        scanf("%d", &exec);
        printf("Enter the arrival time = ");
        scanf("%d", &arrival);
        printf("\n");
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->id = id;
        temp->execution_time = exec;
        temp->arrival_time = arrival;
        temp->remaining_time = exec;
        temp->next = NULL;
        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            struct node *ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    return start;
}

void display(struct node *start)
{
    if (start == NULL)
    {
        printf("No processes available\n");
        return;
    }

    printf("Processes are:\n");
    printf("ProcessID    Execution Time   Arrival Time\n");
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d\t\t%d\t\t%d\n", ptr->id, ptr->execution_time, ptr->arrival_time);
        ptr = ptr->next;
    }
    printf("\n");
}

void preemptiveSJF(struct node *head)
{
    if (head == NULL)
    {
        printf("No processes available\n");
        return;
    }

    struct node *completed = NULL;
    int current_time = 0;
    int total_tat = 0, total_waiting = 0, process_count = 0;
    int *completion_times = (int *)calloc(1000, sizeof(int));

    printf("ProcessID   Arrival Time   Completion Time   Turnaround Time   Waiting Time\n");

    while (head != NULL)
    {
        struct node *prev = NULL, *ptr = head, *shortest_prev = NULL, *shortest = NULL;
        int min_remaining_time = INT_MAX;

        while (ptr != NULL)
        {
            if (ptr->arrival_time <= current_time && ptr->remaining_time < min_remaining_time && ptr->remaining_time > 0)
            {
                shortest_prev = prev;
                shortest = ptr;
                min_remaining_time = ptr->remaining_time;
            }
            prev = ptr;
            ptr = ptr->next;
        }

        if (shortest == NULL)
        {
            current_time++;
            continue;
        }

        shortest->remaining_time--;
        current_time++;

        if (shortest->remaining_time == 0)
        {
            completion_times[shortest->id] = current_time;
            process_count++;

            if (shortest_prev == NULL)
            {
                head = shortest->next;
            }
            else
            {
                shortest_prev->next = shortest->next;
            }

            int tat = current_time - shortest->arrival_time;
            int waiting = tat - shortest->execution_time;
            total_tat += tat;
            total_waiting += waiting;

            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", shortest->id, shortest->arrival_time, current_time, tat, waiting);

            free(shortest);
        }
    }

    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / process_count);
    printf("Average Waiting Time = %.2f\n", (float)total_waiting / process_count);

    free(completion_times);
}

int main()
{

    printf("Day 6 - Question 1: Preemptive SJF algorithm.\n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");

    struct node *head = create();
    display(head);
    printf("Preemptive SJF Scheduling result:\n");
    preemptiveSJF(head);
    return 0;
}