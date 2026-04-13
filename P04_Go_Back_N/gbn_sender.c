#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <arpa/inet.h>

#define PORT 8080

#define WINDOW_SIZE 3

#define TOTAL_FRAMES 10

int main() {

int sock = 0;

struct sockaddr_in serv_addr;

char buffer[1024] = {0};

int acked = 0, sent = 0;

sock = socket(AF_INET, SOCK_STREAM, 0);

serv_addr.sin_family = AF_INET;

serv_addr.sin_port = htons(PORT);

inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) <
0) {

printf("Connection Failed
");

return -1;

}

printf("\--- SENDER \--- 
Window Size: %d
", WINDOW_SIZE);

while (acked < TOTAL_FRAMES) {

while (sent < acked + WINDOW_SIZE && sent < TOTAL_FRAMES) {

printf("Sending Packet: %d
", sent);

sprintf(buffer, "%d", sent);

send(sock, buffer, strlen(buffer), 0);

sent++;

sleep(1);

}

memset(buffer, 0, 1024);

recv(sock, buffer, 1024, 0);

int received_ack = atoi(&buffer[4]);

if (received_ack == acked) {

printf("Received ACK for %d. Sliding window\...
", acked);

acked++;

} else {

printf("ACK Error! Going back to Packet %d
", acked);

sent = acked;

}

}

printf("All packets delivered successfully.
");

close(sock);

return 0;

}
