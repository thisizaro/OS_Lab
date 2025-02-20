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

    int pid = fork();

    if (pid == 0)
    {
        // child process
        close(fd[1]); // close the write end of the pipe
        read(fd[0], y2, 20);
        printf("Read: %s\n", y2);
        read(fd[0], y2, 20);
        printf("Read: %s\n", y2);
        close(fd[0]); // close the read end of the pipe
    }
    else
    {
        // parent process
        close(fd[0]); // close the read end of the pipe
        printf("Writing to pipe\n");
        write(fd[1], y1[0], 20);
        printf("Writing to pipe\n");
        write(fd[1], y1[1], 20);
        close(fd[1]); // close the write end of the pipe
    }
}