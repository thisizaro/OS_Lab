// Write a program to take to int send it to child process using pipe and then add them and then send it to parent process using pipe and the print it in parent process.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pipe1[2], pipe2[2];
    pid_t pid;
    int num1, num2, sum;

    // Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        exit;
    }

    if (pid > 0)
    {                    // Parent process
        close(pipe1[0]); // Close reading end of pipe1
        close(pipe2[1]); // Close writing end of pipe2

        // Get two integers from user
        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        // Send integers to child process
        write(pipe1[1], &num1, sizeof(num1));
        write(pipe1[1], &num2, sizeof(num2));
        close(pipe1[1]); // Close writing end of pipe1

        // Read the sum from child process
        read(pipe2[0], &sum, sizeof(sum));
        close(pipe2[0]); // Close reading end of pipe2

        // Print the sum
        printf("Sum: %d\n", sum);
    }
    else
    {                    // Child process
        close(pipe1[1]); // Close writing end of pipe1
        close(pipe2[0]); // Close reading end of pipe2

        // Read integers from parent process
        read(pipe1[0], &num1, sizeof(num1));
        read(pipe1[0], &num2, sizeof(num2));
        close(pipe1[0]); // Close reading end of pipe1

        // Calculate sum
        sum = num1 + num2;

        // Send sum to parent process
        write(pipe2[1], &sum, sizeof(sum));
        close(pipe2[1]); // Close writing end of pipe2

        exit(EXIT_SUCCESS);
    }

    return 0;
}