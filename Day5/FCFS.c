#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int pid;
    float bt;
    float at;
    float ct;

    // Extra fields
    float wt;  // Waiting time
    float tat; // Turnaround time

    // Next process
    struct Process *next;

} Process;

void appendProcesss(Process **head, int pid, float bt, float at)
{
    Process *new_process = (Process *)malloc(sizeof(Process));
    new_process->pid = pid;
    new_process->bt = bt;
    new_process->at = at;
    new_process->wt = 0;
    new_process->tat = 0;
    new_process->next = NULL;

    if (*head == NULL)
    {
        *head = new_process;
    }
    else
    {
        Process *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_process;
    }
}

void calculateTimes(Process *head)
{
    int current_time = 0;
    Process *temp = head;
    while (temp != NULL)
    {
        if (current_time < temp->at)
        {
            current_time = temp->at;
        }
        temp->wt = current_time - temp->at;
        temp->tat = temp->wt + temp->bt;
        current_time += temp->bt;
        temp->ct = current_time;
        temp = temp->next;
    }
}

void printAverageTimes(Process *head, int n)
{
    float twt = 0, ttat = 0;
    Process *temp = head;
    while (temp != NULL)
    {
        twt += temp->wt;
        ttat += temp->tat;
        temp = temp->next;
    }
    printf("Average Waiting Time: %.2f\n", twt / n);
    printf("Average Turnaround Time: %.2f\n", ttat / n);
}

void displayProcessDetails(Process *head)
{
    printf("\nProcess Details: \n");
    Process *temp = head;
    printf("PID \t BT \t AT \t WT \t TAT \t CT\n");
    while (temp != NULL)
    {
        printf("P%d \t %.2f \t %.2f \t %.2f \t %.2f \t %.2f\n", temp->pid, temp->bt, temp->at, temp->wt, temp->tat, temp->ct);
        temp = temp->next;
    }
    printf("\n");
}

void displayGanttChart(Process *head)
{
    printf("\nGantt chart: \n");
    Process *temp = head;
    printf("PID \t | \t ");
    while (temp != NULL)
    {
        printf("P%d \t | \t ", temp->pid);
        temp = temp->next;
    }

    // Display completion time
    temp = head;
    printf("\nTime: \t0\t");
    while (temp != NULL)
    {
        printf("| \t %.2f \t", temp->ct);
        temp = temp->next;
    }
    printf("\n");
}

// Source code by Aro.
int main()
{
    int n, pid, bt, at;
    Process *head = NULL;

    printf("Enter the number of process: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter process ID, burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d %d", &pid, &bt, &at);
        appendProcesss(&head, pid, bt, at);
    }

    // Calculate waiting time and turnaround time
    calculateTimes(head);

    printf("\nFCFS Scheduling: \n");
    // Display process details
    displayProcessDetails(head);

    // Calculate average waiting time and average turnaround time
    printAverageTimes(head, n);

    // Display horizontal gantt chart.
    displayGanttChart(head);
}