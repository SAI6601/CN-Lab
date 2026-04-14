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
    int expected_frame = 0, frame, total_frames, ack;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Receiver waiting...\n");
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

    recv(new_socket, &total_frames, sizeof(total_frames), 0);
    printf("Total frames to receive: %d\n", total_frames);

    while (expected_frame < total_frames) {
        recv(new_socket, &frame, sizeof(frame), 0);
        if (frame == expected_frame) {
            printf("Frame %d received\n", frame);
            ack = frame;
            expected_frame++;
        } else {
            printf("Frame %d out of order. Expected %d. Sending NAK.\n", frame, expected_frame);
            ack = -1;
        }
        send(new_socket, &ack, sizeof(ack), 0);
    }
    printf("All frames received.\n");
    close(new_socket);
    close(server_fd);
    return 0;
}
