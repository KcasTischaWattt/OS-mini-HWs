#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile int received_number = 0;
volatile int bit_count = 0;

void sigusr_handler(int sig) {
    if (sig == SIGUSR1) {
        received_number |= (1 << bit_count);
    }
    bit_count++;
}

int main() {
    printf("Receiver PID: %d\n", getpid());
    printf("Enter the transmitter's PID: ");
    int transmitter_pid;
    scanf("%d", &transmitter_pid);

    struct sigaction action;
    action.sa_handler = sigusr_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    while (bit_count < 32) {
        pause();
    }

    printf("Received integer: %d\n", received_number);
    return 0;
}
