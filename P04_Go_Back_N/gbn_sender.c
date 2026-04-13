#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define WINDOW_SIZE 4
#define MAX_FRAMES 10

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    int total_frames, ack;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);
    send(sock, &total_frames, sizeof(total_frames), 0);

    int base = 0, next_frame = 0;
    while (base < total_frames) {
        while (next_frame < base + WINDOW_SIZE && next_frame < total_frames) {
            printf("Sending frame %d\n", next_frame);
            send(sock, &next_frame, sizeof(next_frame), 0);
            next_frame++;
        }
        recv(sock, &ack, sizeof(ack), 0);
        if (ack == -1) {
            printf("NAK received. Resending from frame %d\n", base);
            next_frame = base;
        } else {
            printf("ACK received for frame %d\n", ack);
            base = ack + 1;
        }
    }
    printf("All frames sent successfully.\n");
    close(sock);
    return 0;
}
