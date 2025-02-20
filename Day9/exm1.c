#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd[2];

    int x;
    char y1[2][20] = {"Hello", "World"};
    char y2[20];

    x = pipe(fd);
    if (x == -1)
    {
        printf("Pipe failed\n");
        return 1;
    }
    printf("Writing to pipe\n");
    write(fd[1], y1[0], 20);
    printf("Reading from pipe\n");
    read(fd[0], y2, 20);
    printf("Read: %s\n", y2);
    printf("Writing to pipe\n");
    write(fd[1], y1[1], 20);
    printf("Reading from pipe\n");
    read(fd[0], y2, 20);
    printf("Read: %s\n", y2);
    return 0;
}