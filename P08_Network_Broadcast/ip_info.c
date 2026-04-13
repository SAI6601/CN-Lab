#include <stdio.h>

int main() {
    int ip[4], mask[4], network[4], broadcast[4];
    int prefix;

    printf("Enter IP address (e.g. 192.168.1.10): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Enter subnet mask prefix (e.g. 24): ");
    scanf("%d", &prefix);

    int full_octets = prefix / 8;
    int partial_bits = prefix % 8;

    for (int i = 0; i < 4; i++) {
        if (i < full_octets)
            mask[i] = 255;
        else if (i == full_octets)
            mask[i] = 256 - (1 << (8 - partial_bits));
        else
            mask[i] = 0;
    }

    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (~mask[i] & 255);
    }

    int total = 1 << (32 - prefix);

    printf("\nNetwork Address : %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of Addresses: %d\n", total);

    return 0;
}
