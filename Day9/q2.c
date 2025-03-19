#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("Day 9 - Question 1: Write a program that creates n level process structure where each\n level consists of exactly one process. Here every parent process makes some modification to the\n original message and sends it to its child and this process repeats till it reached at the last \nchild in the process tree. \n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");

    int fd[2][2];

    for (int i = 0; i < 2; i++)
    {
        if (pipe(fd[i]) == -1)
        {
            printf("Pipe failed\n");
            return 1;
        }
    }

    char s[1][20] = {"Hello"};

    int firstChild = fork();

    if (firstChild == 0)
    {
        printf("First child process\n");

        close(fd[0][1]); // Close write end of pipe 1
        read(fd[0][0], s[0], 20);
        printf("Read: %s\n", s[0]);
        close(fd[0][0]); // Close read end of pipe 1

        s[0][0] = 'h';
        printf("Written by child 1: %s\n", s[0]);

        close(fd[1][0]); // Close read end of pipe 2
        write(fd[1][1], s[0], 20);
        close(fd[1][1]); // Close write end of pipe 2

        int secondChild = fork();

        if (secondChild == 0)
        {
            // Second child process
            printf("Second child process\n");

            close(fd[1][1]); // Close write end of pipe 2
            read(fd[1][0], s[0], 20);
            printf("Read: %s\n", s[0]);
            close(fd[1][0]); // Close read end of pipe 2

            s[0][1] = 'O';
            printf("Written by child 2: %s\n", s[0]);

            close(fd[0][0]); // Close read end of pipe 1
            write(fd[0][1], s[0], 20);
            close(fd[0][1]); // Close write end of pipe 1

            int thirdChild = fork();

            if (thirdChild == 0)
            {
                // Third child process
                printf("Third child process\n");

                close(fd[0][1]); // Close write end of pipe 1
                read(fd[0][0], s[0], 20);
                printf("Read: %s\n", s[0]);
                close(fd[0][0]); // Close read end of pipe 1

                s[0][2] = 'L';
                printf("Written by child 3: %s\n", s[0]);

                close(fd[1][0]); // Close read end of pipe 2
                write(fd[1][1], s[0], 20);
                close(fd[1][1]); // Close write end of pipe 2

                return 0;
            }
            else
            {
                wait(NULL); // Wait for third child to finish
            }
            return 0;
        }
        else
        {
            wait(NULL); // Wait for second child to finish
        }
        return 0;
    }
    else
    {
        printf("Parent process\n");

        close(fd[1][1]); // Close write end of pipe 2
        write(fd[0][1], s[0], 20);
        close(fd[0][1]); // Close write end of pipe 1

        wait(NULL); // Wait for first child to finish

        read(fd[1][0], s[0], 20);
        printf("Read: %s\n", s[0]);
        close(fd[1][0]); // Close read end of pipe 2

        s[0][0] = 'H';
        printf("Written by parent: %s\n", s[0]);
    }

    return 0;
}
