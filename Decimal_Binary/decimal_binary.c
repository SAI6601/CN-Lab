// #include <stdio.h>

// int main() {
//     int n, binary[32], i = 0;

//     printf("Enter decimal number: ");
//     scanf("%d", &n);

//     while (n > 0) {
//         binary[i++] = n % 2;
//         n = n / 2;
//     }

//     printf("Binary: ");
//     for (int j = i - 1; j >= 0; j--) {
//         printf("%d", binary[j]);
//     }
//     printf("\n");

//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function: Decimal → Binary (8-bit)
void decToBin(int num, char *bin) {
    for(int i = 7; i >= 0; i--) {
        bin[7 - i] = ((num >> i) & 1) + '0';
    }
    bin[8] = '\0';
}

// Function: Binary → Decimal
int binToDec(char *bin) {
    int dec = 0;
    for(int i = 0; i < 8; i++) {
        dec = dec * 2 + (bin[i] - '0');
    }
    return dec;
}

int main() {
    int choice;

    printf("\n--- IP ADDRESS CONVERSION ---\n");
    printf("1. Decimal IP to Binary IP\n");
    printf("2. Binary IP to Decimal IP\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        char ip[20];
        int a, b, c, d;
        char bin[9];

        printf("Enter IP (e.g., 192.168.1.1): ");
        scanf("%s", ip);

        sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);

        printf("Binary IP: ");
        decToBin(a, bin); printf("%s.", bin);
        decToBin(b, bin); printf("%s.", bin);
        decToBin(c, bin); printf("%s.", bin);
        decToBin(d, bin); printf("%s\n", bin);
    }

    else if(choice == 2) {
        char ip[50];
        char part[9];
        int i = 0, j = 0;

        printf("Enter Binary IP (e.g., 11000000.10101000.00000001.00000001): ");
        scanf("%s", ip);

        printf("Decimal IP: ");

        while(1) {
            if(ip[i] == '.' || ip[i] == '\0') {
                part[j] = '\0';
                printf("%d", binToDec(part));

                if(ip[i] == '\0') break;
                printf(".");
                j = 0;
            } else {
                part[j++] = ip[i];
            }
            i++;
        }
        printf("\n");
    }

    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
