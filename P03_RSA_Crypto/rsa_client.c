#include <stdio.h>

#include <unistd.h>

#include <arpa/inet.h>

#define PORT 8080

long mod_exp(long base, long exp, long mod) {

long result = 1;

while(exp > 0) {

if(exp % 2 == 1)

result = (result * base) % mod;

base = (base * base) % mod;

exp /= 2;

}

return result;

}

int main() {

int sock;

struct sockaddr_in serv_addr;

char msg;

long e = 3, n = 33; // RSA public key

sock = socket(AF_INET, SOCK_STREAM, 0);

serv_addr.sin_family = AF_INET;

serv_addr.sin_port = htons(PORT);

inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

printf("Enter a character: ");

scanf("%c", &msg);

long encrypted = mod_exp((int)msg, e, n);

printf("Encrypted value: %ld
", encrypted);

send(sock, &encrypted, sizeof(encrypted), 0);

close(sock);

}
