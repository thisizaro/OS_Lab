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
        printf("Hello \n");
    }
    else
    {
        printf("World \n");
    }

    return 0;
}
