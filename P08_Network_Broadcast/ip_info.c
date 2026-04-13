#include <stdio.h>

#include <math.h>

int main() {

int ip[4], cidr;

int mask[4] = {0};

int network[4], broadcast[4];

int i;

printf("Enter IP (e.g. 192 168 1 10): ");

scanf("%d %d %d %d", &ip[0], &ip[1], &ip[2], &ip[3]);

printf("Enter CIDR (e.g. 24): ");

scanf("%d", &cidr);

// Generate subnet mask

int bits = cidr;

for(i = 0; i < 4; i++) {

if(bits >= 8) {

mask[i] = 255;

bits -= 8;

} else {

mask[i] = 256 - (int)pow(2, 8 - bits);

bits = 0;

}

}

// Network Address

for(i = 0; i < 4; i++)

network[i] = ip[i] & mask[i];

// Broadcast Address

for(i = 0; i < 4; i++)

broadcast[i] = network[i] \| (\~mask[i] & 255);

int total = pow(2, (32 - cidr));

printf("
Network Address: %d.%d.%d.%d",

network[0], network[1], network[2], network[3]);

printf("
Broadcast Address: %d.%d.%d.%d",

broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

printf("
Number of Addresses: %d
", total);

return 0;

}
