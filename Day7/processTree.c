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

    b = fork();
    if (b == 0)
    { // Process B
        d = fork();
        if (d == 0)
        { // Process D
            print_number(12, 5);
            exit(0);
        }

        e = fork();
        if (e == 0)
        { // Process E
            f = fork();
            if (f == 0)
            { // Process F
                print_number(14, 4);
                exit(0);
            }

            g = fork();
            if (g == 0)
            { // Process G
                print_number(15, 3);
                exit(0);
            }

            sleep(6); // Wait for F and G
            print_number(13, 2);
            exit(0);
        }

        sleep(7); // Wait for D and E
        print_number(10, 1);
        exit(0);
    }

    c = fork();
    if (c == 0)
    { // Process C
        print_number(11, 0);
        exit(0);
    }

    // Parent process A waits for all child processes
    sleep(10);
    return 0;
}
