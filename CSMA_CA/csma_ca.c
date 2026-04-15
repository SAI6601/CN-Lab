#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int attempts = 0;
    int max_attempts = 10;
    srand(time(0));

    while (attempts < max_attempts) {
        printf("\nAttempt %d:\n", attempts + 1);

        // Step 1: Sense channel
        int channel_busy = rand() % 2;
        if (channel_busy) {
            printf("Channel busy. Waiting (backoff)...\n");
        } else {
            printf("Channel idle. Sending RTS...\n");

            // Step 2: RTS/CTS mechanism
            int cts_received = rand() % 2;
            if (cts_received) {
                printf("CTS received. Transmitting data...\n");
                printf("Data sent successfully!\n");
                break;
            } else {
                printf("No CTS received. Retrying...\n");
                attempts++;
            }
        }
    }

    if (attempts == max_attempts)
        printf("Transmission failed.\n");

    return 0;
}
