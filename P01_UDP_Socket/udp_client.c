#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <arpa/inet.h>

#include <unistd.h>

#define PORT 8080

#define BUFFER_SIZE 1024

int main() {

int sockfd;

char buffer[BUFFER_SIZE];

char *message = "Hello from client";

struct sockaddr_in server_addr;

socklen_t addr_len;

sockfd = socket(AF_INET, SOCK_DGRAM, 0);

server_addr.sin_family = AF_INET;

server_addr.sin_port = htons(PORT);

server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

sendto(sockfd, message, strlen(message), 0,

(struct sockaddr *)&server_addr, sizeof(server_addr));

addr_len = sizeof(server_addr);

recvfrom(sockfd, buffer, BUFFER_SIZE, 0,

(struct sockaddr *)&server_addr, &addr_len);

printf("Server: %s
", buffer);

close(sockfd);

return 0;

}
