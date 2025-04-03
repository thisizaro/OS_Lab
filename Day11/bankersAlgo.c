#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int num_processes, num_resources;

void inputData()
{
    printf("Day 10 - Question 1: Banker's Algorithm. \n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter available resources: \n");
    for (int i = 0; i < num_resources; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("Enter maximum resource matrix: \n");
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocation matrix: \n");
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int isSafeState()
{
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    for (int i = 0; i < num_resources; i++)
    {
        work[i] = available[i];
    }

    while (count < num_processes)
    {
        int found = 0;
        for (int i = 0; i < num_processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < num_resources; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == num_resources)
                {
                    for (int k = 0; k < num_resources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
        {
            printf("System is in an unsafe state!\n");
            return 0;
        }
    }

    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < num_processes; i++)
    {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

int main()
{
    inputData();
    isSafeState();
    return 0;
}
