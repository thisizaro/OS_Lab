#include <stdio.h>
#include <stdlib.h>

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

void roundRobin(struct node *head, int quantum)
{
    if (head == NULL)
    {
        printf("No processes available\n");
        return;
    }

    struct node *ready_queue = NULL;
    int current_time = 0;
    int total_tat = 0, total_waiting = 0, process_count = 0;
    int *completion_times = (int *)calloc(1000, sizeof(int));

    printf("ProcessID   Arrival Time   Completion Time   Turnaround Time   Waiting Time\n");

    while (head != NULL || ready_queue != NULL)
    {
        while (head != NULL && head->arrival_time <= current_time)
        {
            struct node *temp = head;
            head = head->next;
            temp->next = ready_queue;
            ready_queue = temp;
        }

        if (ready_queue == NULL)
        {
            current_time++;
            continue;
        }

        struct node *current = ready_queue;
        ready_queue = ready_queue->next;

        if (current->remaining_time <= quantum)
        {
            current_time += current->remaining_time;
            current->remaining_time = 0;
        }
        else
        {
            current_time += quantum;
            current->remaining_time -= quantum;
        }

        if (current->remaining_time == 0)
        {
            completion_times[current->id] = current_time;
            process_count++;

            int tat = current_time - current->arrival_time;
            int waiting = tat - current->execution_time;
            total_tat += tat;
            total_waiting += waiting;

            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", current->id, current->arrival_time, current_time, tat, waiting);

            free(current);
        }
        else
        {
            struct node *temp = ready_queue;
            if (temp == NULL)
            {
                ready_queue = current;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = current;
            }
            current->next = NULL;
        }
    }

    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / process_count);
    printf("Average Waiting Time = %.2f\n", (float)total_waiting / process_count);

    free(completion_times);
}

int main()
{
    printf("Day 6 - Question 2: Round Robin algorithm.\n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");

    struct node *head = create();
    display(head);
    int quantum;
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    printf("Round Robin Scheduling result:\n");
    roundRobin(head, quantum);
    return 0;
}