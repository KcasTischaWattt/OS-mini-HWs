#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

// Функция для вычисления числа Фибоначчи
int fibonacci(int n) {
    if (n <= 1)
        return n;  // Возвращаем n, если n <= 1 (базовый случай)
    else
        return fibonacci(n-1) + fibonacci(n-2);  // Рекурсивно вычисляем числа Фибоначчи
}

// Функция для вычисления факториала
int factorial(int n) {
    if (n == 0)
        return 1;  // Возвращаем 1, если n = 0 (базовый случай)
    else
        return n * factorial(n-1);  // Рекурсивно вычисляем факториал
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("One argument is required.\n");
        return 1;
    }

    int n = atoi(argv[1]);  // Преобразуем аргумент командной строки в целое число

    pid_t pid = fork();  // Создаем новый процесс с помощью fork()

    if (pid == 0) {
        // Код, выполняемый в дочернем процессе
        printf("Factorial of %d: %d\n", n, factorial(n));  // Выводим результат вычисления факториала
    } else if (pid > 0) {
        // Код, выполняемый в родительском процессе
        printf("Fibonacci number %d: %d\n", n, fibonacci(n));  // Выводим результат вычисления числа Фибоначчи
    } else {
        // Обработка ошибки при создании процесса
        printf("Failed to create a process.\n");
        return 1;
    }

    return 0;
}
