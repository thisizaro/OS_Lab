#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sec = atoi(argv[1]);

    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child with PID %d will be waiting for %d seconds.\n", getpid(), sec);
        sleep(sec);
        printf("Child with PID %d has slept for %d seconds\n", getpid(), sec);
        exit(0);
    }
    else
    {
        printf("Parent with PID %d\n", getpid());
    }
    // Wait for child process pid to end.
    waitpid(pid, NULL, 0);
    printf("Process with PID %d has ended\n", getpid());

    return 0;
}