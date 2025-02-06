#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t x;
    x = fork();

    if (x < 0)
    {
        printf("Error");
    }
    else if (x > 0)
    {
        printf("Parent process is running.\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        printf("Child PID: %d\n", x);
        printf("Parent process is exiting. Child can run now. \n");
    }
    else
    {
        printf("Child process is running.\n");
        sleep(1);
        printf("Child process is now orphaned and adopted by init.\n");
        printf("Parent PID: %d\n", getppid());
        printf("PID: %d\n", getpid());
    }
}

/*
// A zombie process is a process that has completed execution but still has an entry in the process table.
// This occurs when the parent process has not yet read the exit status of the child process using the wait() system call.
// To create a zombie process, you can modify the code as follows:

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t x;
    x = fork();

    if (x < 0)
    {
        printf("Error");
    }
    else if (x > 0)
    {
        printf("Parent process is running.\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", x);
        sleep(10); // Give time for the child process to exit
        printf("Parent process is exiting.\n");
    }
    else
    {
        printf("Child process is running.\n");
        printf("Child PID: %d\n", getpid());
        printf("Child process is exiting.\n");
        _exit(0); // Child process exits
    }


    // Parent process waits for the child process to exit
    wait(NULL);
    printf("Parent process has cleaned up the zombie process.\n");
    return 0;
}
*/