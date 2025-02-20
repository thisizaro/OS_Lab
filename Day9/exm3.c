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
        close(fd[0]); // close the read end of the pipe
        int c;
        printf("Enter a number: ");
        scanf("%d", &c);

        write(fd[1], &c, sizeof(int));
        close(fd[1]); // close the write end of the pipe
    }
    else
    {
        // parent process
        close(fd[1]); // close the write end of the pipe
        int c;
        read(fd[0], &c, sizeof(int));
        printf("Square of the number is: %d\n", (c * c));
        close(fd[0]); // close the read end of the pipe
    }
    return 0;
}