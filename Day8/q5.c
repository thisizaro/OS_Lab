#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Wap to check that if both parent and child read samme file and point the reading char, then what will impact on the output.

    FILE *file;
    file = open("file.txt", "r");
    char c;
    pid_t pid = fork();
    if (pid == 0)
    {
        c = read(file);
        printf("Child: %c\n", c);
    }
    else
    {
        c = read(file);
        printf("Parent: %c\n", c);
    }
    return 0;
}