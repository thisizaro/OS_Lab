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
    else if (x == 0)
    {
        printf("Hello! \n");
        printf("My PID is %d \n", getpid());
        printf("My parent's PID is %d \n", getppid());
    }
    else
    {
        printf("World \n");
        printf("My PID is %d \n", getpid());
        printf("My parent's PID is %d \n", getppid());
        printf("My Childs's PID is %d \n", x);
    }

    return 0;
}
