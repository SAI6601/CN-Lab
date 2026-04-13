#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <arpa/inet.h>

#define PORT 9090

#define TOTAL_FRAMES 5

#define WINDOW_SIZE 3

int main() {

int sock;

struct sockaddr_in receiver;

int base = 0, next = 0;

int ack;

sock = socket(AF_INET, SOCK_STREAM, 0);

receiver.sin_family = AF_INET;

receiver.sin_addr.s_addr = inet_addr("127.0.0.1");

receiver.sin_port = htons(PORT);

if (connect(sock, (struct sockaddr*)&receiver, sizeof(receiver)) < 0)
{

printf("Connection failed!
");

return 1;

}

printf("Sender connected to receiver

");

while (base < TOTAL_FRAMES) {

while (next < base + WINDOW_SIZE && next < TOTAL_FRAMES) {

printf("Sending frame %d
", next);

send(sock, (char*)&next, sizeof(next), 0);

next++;

}

int bytes = recv(sock, (char*)&ack, sizeof(ack), 0);

if (bytes <= 0) break;

printf("Received ACK %d

", ack);

base = ack + 1;

}

int end = -1;

send(sock, (char*)&end, sizeof(end), 0);

close(sock);

return 0;

}
