#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Execution of a.c program\n");
    printf("PID of a.c program is %d\n", getpid());
    execv("./prog2.out", argv);
    printf("End of a.c program.");
    return 0;
}