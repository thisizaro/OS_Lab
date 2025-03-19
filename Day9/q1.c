#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Day 9 - Question 1: Write a program that creates n level process structure where each level consists of exactly one process. Here every parent process makes some modification to the original message and sends it to its child and this process repeats till it reached at the last child in the process tree. \n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");
    int fd[2];
    int x = pipe(fd);

    if (x == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    int s = 0;

    int pid = fork();
    if (pid == 0)
    {
        // Child process;
        int sum = 0;
        for (int i = 5; i < 10; i++)
        {
            sum += arr[i];
        }
        close(fd[0]); // close the read end of the pipe
        write(fd[1], &sum, sizeof(int));
        close(fd[1]); // close the write end of the pipe
    }
    else
    {
        // Parent process
        int sum = 0;
        for (int i = 1; i < 5; i++)
        {
            sum += arr[i];
        }
        close(fd[1]); // close the write end of the pipe
        read(fd[0], &s, sizeof(int));
        close(fd[0]); // close the read end of the pipe

        printf("Sum of first half: %d\n", sum);
        sum += s;
        printf("Sum of all elements: %d\n", sum);
    }
}