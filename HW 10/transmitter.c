#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int receiver_pid, number;
    printf("Transmitter PID: %d\n", getpid());
    printf("Enter the receiver's PID: ");
    scanf("%d", &receiver_pid);

    printf("Enter an integer to send: ");
    scanf("%d", &number);

    for (int i = 0; i < 32; ++i) {
        int bit = (number >> i) & 1;
        if (bit) {
            kill(receiver_pid, SIGUSR1);
        } else {
            kill(receiver_pid, SIGUSR2);
        }
        usleep(1000);
    }

    return 0;
}
