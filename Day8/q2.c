#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Child process is executing its task.\n");
        printf("Child process is printing the string: %s\n", argv[1]);
        exit(0);
    }
    else
    {
        printf("Parent process is executing its task.\n");
    }

    return 0;
}