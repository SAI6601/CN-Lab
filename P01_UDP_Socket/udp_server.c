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

char *message = "Hello from server";

struct sockaddr_in server_addr, client_addr;

socklen_t addr_len;

sockfd = socket(AF_INET, SOCK_DGRAM, 0);

server_addr.sin_family = AF_INET;

server_addr.sin_port = htons(PORT);

server_addr.sin_addr.s_addr = INADDR_ANY;

bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

printf("UDP Server is running on port %d\...
", PORT);

addr_len = sizeof(client_addr);

recvfrom(sockfd, buffer, BUFFER_SIZE, 0,

(struct sockaddr *)&client_addr, &addr_len);

printf("Client: %s
", buffer);

sendto(sockfd, message, strlen(message), 0,

(struct sockaddr *)&client_addr, addr_len);

close(sockfd);

return 0;

}
