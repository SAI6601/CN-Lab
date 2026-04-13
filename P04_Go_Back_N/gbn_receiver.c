#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <arpa/inet.h>

#define PORT 8080

int main() {

int server_fd, new_socket;

struct sockaddr_in address;

int addrlen = sizeof(address);

int expected_frame = 0;

char buffer[1024] = {0};

server_fd = socket(AF_INET, SOCK_STREAM, 0);

address.sin_family = AF_INET;

address.sin_addr.s_addr = INADDR_ANY;

address.sin_port = htons(PORT);

bind(server_fd, (struct sockaddr *)&address, sizeof(address));

listen(server_fd, 3);

printf("\--- RECEIVER \--- 
Waiting for connection\...
");

new_socket = accept(server_fd, (struct sockaddr *)&address,

(socklen_t*)&addrlen);

while (1) {

memset(buffer, 0, 1024);

int valread = read(new_socket, buffer, 1024);

if (valread <= 0) break;

int received_frame = atoi(buffer);

printf("Packet Received: %d \| ", received_frame);

if (received_frame == expected_frame) {

printf("Status: SUCCESS. Sending ACK %d
", expected_frame);

sprintf(buffer, "ACK %d", expected_frame);

send(new_socket, buffer, strlen(buffer), 0);

expected_frame++;

} else {

printf("Status: OUT OF ORDER. Expected %d. Resending ACK %d
",

expected_frame, expected_frame - 1);

sprintf(buffer, "ACK %d", expected_frame - 1);

send(new_socket, buffer, strlen(buffer), 0);

}

}

close(new_socket);

close(server_fd);

return 0;

}
