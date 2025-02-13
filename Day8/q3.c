#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Wap to check that if both parent and child access and update the pointer variable value, then what will  be the impact on output.
    int x = 10;
    int *ptr = &x;
    pid_t pid = fork();
    if (pid == 0)
    {
        *ptr = 20;
        printf("Child: x = %d\n", x);
    }
    else
    {
        *ptr = 30;
        printf("Parent: x = %d\n", x);
    }

    return 0;
}