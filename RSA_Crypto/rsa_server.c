#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

long mod_exp(long base, long exp, long mod) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int encrypted;
    long d = 7, n = 33;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("RSA Server waiting...\n");

    new_socket = accept(server_fd, NULL, NULL);
    recv(new_socket, &encrypted, sizeof(encrypted), 0);

    long decrypted = mod_exp(encrypted, d, n);
    printf("Encrypted received: %d\n", encrypted);
    printf("Decrypted message (ASCII): %ld\n", decrypted);
    printf("Character: %c\n", (char)decrypted);

    close(new_socket);
    close(server_fd);
    return 0;
}
