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
            printf("Channel is busy. Waiting...\n");
        } else {
            printf("Channel is idle. Sending data...\n");

            // Step 2: Collision detection
            int collision = rand() % 2;
            if (collision) {
                printf("Collision detected! Stopping transmission...\n");
                attempts++;
                int backoff = rand() % 5;
                printf("Waiting for %d time units before retry...\n", backoff);
            } else {
                printf("Data transmitted successfully!\n");
                break;
            }
        }
    }

    if (attempts == max_attempts)
        printf("Transmission failed after maximum attempts.\n");

    return 0;
}
