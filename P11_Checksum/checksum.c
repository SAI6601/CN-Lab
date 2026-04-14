#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int i, sum = 0;

    printf("Enter binary data: ");
    scanf("%s", data);

    // Add bits
    for (i = 0; i < strlen(data); i++) {
        sum += data[i] - '0';
    }

    // Add carry
    while (sum > 1) {
        sum = (sum / 2) + (sum % 2);
    }

    // 1's complement
    int checksum = (sum == 0) ? 1 : 0;
    printf("Checksum: %d\n", checksum);

    return 0;
}
