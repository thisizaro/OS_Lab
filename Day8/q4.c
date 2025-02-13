#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Wap without using sleep and wait function, where child will perform task first then parent will perform it's task.

    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Child process is executing its task.\n");
        // Child process task here
        exit(0);
    }
    else
    {
        // Parent process
        wait(NULL); // Wait for child to complete
        printf("Parent process is executing its task.\n");
        // Parent process task here
    }

    return 0;
}