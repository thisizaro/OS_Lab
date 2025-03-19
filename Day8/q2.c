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
        printf("Child process is printing the string:\n");
        execv("./q2_printer.out", argv);
        exit(0);
    }
    else
    {
        printf("Parent process is executing its task.\n");
    }

    return 0;
}
