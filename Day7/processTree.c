#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void print_number(int num, int delay)
{
    sleep(delay); // Ensure proper sequence using sleep
    printf("%d\n", num);
    fflush(stdout);
}

int main()
{
    pid_t b, c, d, e, f, g;
    // process sequence: 11, 10, 15, 14, 13, 12

    /*
    process tree:

          A
     /        \
    B(10)      C(11)
    /  \
D(12)  E(13)
     /   \
F(14)  G(15)

    */

    b = fork();

    if (b == 0)
    {
        // Process B
        sleep(0.5); // Wait for C

        d = fork();

        if (d == 0)
        {
            // Process D
            sleep(1); // Wait for E
            print_number(12, 5);
            exit(1);
        }

        e = fork();

        if (e == 0)
        {
            // Process E has "1 second" to complete everything before process D starts. (13)
            f = fork();

            if (f == 0)
            {
                // Process F wait for 0.5 seconds for G to execute. (14)
                sleep(0.2);
                // printf("Process F executed: %d\n", getpid());
                print_number(14, 4);
                exit(1);
            }

            g = fork();

            if (g == 0)
            {
                // Process G (15)
                // printf("Process G executed: %d\n", getpid());
                print_number(15, 3);
                // printf("\n");
                exit(1);
            }

            if (f > 0 && g > 0)
            {
                // Process E (12)
                sleep(1);
                // printf("Process E executed: %d\n", getpid());
                print_number(13, 1);
                // printf("\n");
                exit(1);
            }
        }

        if (d > 0 && e > 0)
        {
            // Process B (10)
            // printf("Process B executed: %d\n", getpid());
            print_number(10, 2);
            // printf("\n");
            exit(1);
        }
    }

    c = fork();
    if (c == 0)
    {
        // Process C (11)
        // printf("Process C executed: %d\n", getpid());
        print_number(11, 0);
        // printf("\n");
        exit(1);
    }

    // Parent process A waits for all child processes
    sleep(10);
    exit(1);
}
