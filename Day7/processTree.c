#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_number(int num)
{
    printf("%d\n", num);
    fflush(stdout);
}

int main()
{
    int pipeB[2], pipeD[2], pipeE[2], pipeF[2], pipeG[2];

    // Create pipes for synchronization
    pipe(pipeB);
    pipe(pipeD);
    pipe(pipeE);
    pipe(pipeF);
    pipe(pipeG);

    pid_t b, c, d, e, f, g;

    c = fork();
    if (c == 0)
    {
        // Process C (Executes first)
        print_number(11);
        write(pipeB[1], "x", 1); // Unblock B
        exit(0);
    }

    b = fork();
    if (b == 0)
    {
        // Process B (Waits for A)
        read(pipeB[0], NULL, 1);
        print_number(10);

        e = fork();
        if (e == 0)
        {
            g = fork();
            if (g == 0)
            {
                // Process G (Executes first in this subtree)
                print_number(15);
                write(pipeF[1], "x", 1); // Unblock F
                exit(0);
            }

            f = fork();
            if (f == 0)
            {
                // Process F (Waits for G)
                read(pipeF[0], NULL, 1);
                print_number(14);
                write(pipeE[1], "x", 1); // Unblock E
                exit(0);
            }

            // Process E (Waits for F)
            read(pipeE[0], NULL, 1);
            print_number(13);
            write(pipeD[1], "x", 1); // Unblock D
            exit(0);
        }

        d = fork();
        if (d == 0)
        {
            // Process D (Waits for E)
            read(pipeD[0], NULL, 1);
            print_number(12);
            exit(0);
        }

        // Process B waits for E and D
        wait(NULL);
        wait(NULL);
        exit(0);
    }

    // Parent waits for B and C
    wait(NULL);
    wait(NULL);

    return 0;
}
