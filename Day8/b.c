#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Execution of b.c program\n");
    printf("PID of b.c program is %d\n", getpid());
    return 0;
}