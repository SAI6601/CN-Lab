#include <stdio.h>
#include <string.h>

void xor(char *a, char *b, int n) {
    for (int i = 1; i < n; i++) {
        a[i] = (a[i] == b[i]) ? '0' : '1';
    }
}

int main() {
    char data[50], key[20];
    char temp[50], rem[20];
    int data_len, key_len;

    printf("Enter data: ");
    scanf("%s", data);
    printf("Enter key (divisor): ");
    scanf("%s", key);

    data_len = strlen(data);
    key_len = strlen(key);

    strcpy(temp, data);

    // Append zeros
    for (int i = 0; i < key_len - 1; i++) {
        temp[data_len + i] = '0';
    }
    temp[data_len + key_len - 1] = '\0';

    for (int i = 0; i < data_len; i++) {
        if (temp[i] == '1') {
            xor(&temp[i], key, key_len);
        }
    }

    // Extract remainder
    strncpy(rem, &temp[data_len], key_len - 1);
    rem[key_len - 1] = '\0';

    printf("CRC: %s\n", rem);

    return 0;
}
