#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binaryToDecimal(char *bin) {
    int num = 0;
    while (*bin) {
        num = num * 2 + (*bin - '0');
        bin++;
    }
    return num;
}

void decimalToBinary(int num) {
    int binary[8];
    for (int i = 7; i >= 0; i--) {
        binary[i] = num % 2;
        num = num / 2;
    }
    for (int i = 0; i < 8; i++)
        printf("%d", binary[i]);
}

int main() {
    int choice;
    char ip[100];
    char temp[100];
    int octet;

    printf("===== IP Address Converter =====\n");
    printf("1. Binary to Decimal\n");
    printf("2. Decimal to Binary\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter binary IP (e.g. 11000000.10101000.00000001.00000001): ");
        scanf("%s", ip);
        char *token = strtok(ip, ".");
        int first = 1;
        while (token != NULL) {
            if (!first) printf(".");
            printf("%d", binaryToDecimal(token));
            first = 0;
            token = strtok(NULL, ".");
        }
        printf("\n");
    } else if (choice == 2) {
        printf("Enter decimal IP (e.g. 192.168.1.1): ");
        scanf("%s", ip);
        char *token = strtok(ip, ".");
        int first = 1;
        while (token != NULL) {
            if (!first) printf(".");
            decimalToBinary(atoi(token));
            first = 0;
            token = strtok(NULL, ".");
        }
        printf("\n");
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
