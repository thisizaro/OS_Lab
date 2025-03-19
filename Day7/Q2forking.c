#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    printf("Day 7 - Question 2: Program in which parent process waits for child process.\n");
    printf("                                            Coded by Aranya Dutta - 23051490\n");
    printf("For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab\n");
    printf("-----------------------------------------------------------------------------\n\n");
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
