#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // Create 5 child processes and print like this...
    // Child process: x; Parent process: y
    printf("Parent process: %d\n", getpid());
    printf("Init process: %d\n", getppid());

    pid_t x;
    for (int i = 0; i < 5; i++)
    {
        x = fork();
        if (x == 0)
        {
            printf("Child process: %d; Parent process: %d\n", getpid(), getppid());
            break;
        }
    }

    for (int i = 0; i < 5; i++)
        wait(NULL);
    if (x > 0)
    {
        printf("Parent process exiting.\n");
        // printf("11, 10, 15, 14, 13, 12");
    }
    return 0;
}
