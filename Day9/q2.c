#include <stdio.h>
#include <unistd.h>

int main()
{
    // NOT COMPLETED YET!!

    int fd[2];

    int x = pipe(fd);
    if (x == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }
}