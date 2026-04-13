#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define WINDOW_SIZE 4

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int frame, total_frames, ack;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("SR Receiver waiting...\n");
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

    recv(new_socket, &total_frames, sizeof(total_frames), 0);
    printf("Expecting %d frames\n", total_frames);

    int received[100] = {0};
    int count = 0;
    while (count < total_frames) {
        recv(new_socket, &frame, sizeof(frame), 0);
        if (!received[frame]) {
            received[frame] = 1;
            count++;
            printf("Frame %d received. Sending ACK.\n", frame);
        } else {
            printf("Duplicate frame %d. Sending ACK anyway.\n", frame);
        }
        ack = frame;
        send(new_socket, &ack, sizeof(ack), 0);
    }
    printf("All frames received.\n");
    close(new_socket);
    close(server_fd);
    return 0;
}
