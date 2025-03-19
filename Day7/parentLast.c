#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process
            printf("Child process %d with PID %d\n", i + 1, getpid());
            exit(0);
        }
    }

    // Parent process waits for all child processes to terminate
    for (i = 0; i < 5; i++)
    {
        wait(NULL);
    }

    printf("Parent process with PID %d\n", getpid());
    return 0;
}