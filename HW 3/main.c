#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("One argument is required.\n");
        return 1;
    }

    int n = atoi(argv[1]);

    pid_t pid = fork();

    if (pid == 0) {
        printf("Factorial of %d: %d\n", n, factorial(n));
    } else if (pid > 0) {
        printf("Fibonacci number %d: %d\n", n, fibonacci(n));
    } else {
        printf("Failed to create a process.\n");
        return 1;
    }

    return 0;
}
