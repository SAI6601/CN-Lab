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

char *token;

printf("
===== IP Address Converter =====
");

printf("1. Binary to Decimal
");

printf("2. Decimal to Binary
");

printf("Enter your choice: ");

scanf("%d", &choice);

printf("Enter IP address: ");

scanf("%s", ip);

strcpy(temp, ip);

if (choice == 1) {

token = strtok(temp, ".");

while (token != NULL) {

printf("%d", binaryToDecimal(token));

token = strtok(NULL, ".");

if (token != NULL) printf(".");

}

}

else if (choice == 2) {

token = strtok(temp, ".");

while (token != NULL) {

int num = atoi(token);

decimalToBinary(num);

token = strtok(NULL, ".");

if (token != NULL) printf(".");

}

}

else {

printf("Invalid choice!");

}

return 0;

}
