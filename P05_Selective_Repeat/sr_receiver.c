#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <arpa/inet.h>

#define PORT 9090

int main() {

int server_fd, new_socket;

struct sockaddr_in address;

int addrlen = sizeof(address);

int frame;

server_fd = socket(AF_INET, SOCK_STREAM, 0);

address.sin_family = AF_INET;

address.sin_addr.s_addr = INADDR_ANY;

address.sin_port = htons(PORT);

bind(server_fd, (struct sockaddr*)&address, sizeof(address));

listen(server_fd, 1);

printf("Receiver waiting for sender\...
");

new_socket = accept(server_fd, (struct sockaddr*)&address,

(socklen_t*)&addrlen);

printf("Sender connected!

");

while (1) {

int bytes = recv(new_socket, (char*)&frame, sizeof(frame), 0);

if (bytes <= 0) break;

if (frame == -1) {

printf("Transmission completed
");

break;

}

printf("Received frame %d
", frame);

printf("Sending ACK %d

", frame);

send(new_socket, (char*)&frame, sizeof(frame), 0);

}

close(new_socket);

close(server_fd);

return 0;

}
