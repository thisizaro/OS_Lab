#include <stdio.h>

struct Process
{
    int id, arrival_time, burst_time, completion_time, waiting_time, turnaround_time;
};

void sortByBurstTime(struct Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].burst_time > p[j].burst_time)
            {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process p[], int n)
{
    int current_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_time < p[i].arrival_time)
        {
            current_time = p[i].arrival_time;
        }
        current_time += p[i].burst_time;
        p[i].completion_time = current_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

void printProcesses(struct Process p[], int n)
{
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].arrival_time, p[i].burst_time,
               p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        p[i].id = i + 1;
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    sortByBurstTime(p, n);
    calculateTimes(p, n);
    printProcesses(p, n);

    return 0;
}