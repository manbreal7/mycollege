#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345

int setParityBit(int data) {
    int count = 0;
    int temp = data;

    while (temp) {
        count += temp & 1;
        temp >>= 1;
    }

    return (count % 2 == 0) ? (data | (1 << 7)) : data;
}

int main() {
    int data;
    int sockfd;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error connecting to the server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Enter data to transmit (8-bit binary): ");
    scanf("%d", &data);

    if (data < 0 || data > 255) {
        printf("Invalid input. Please enter an 8-bit binary value.\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }


    int transmittedData = setParityBit(data);

    send(sockfd, &transmittedData, sizeof(transmittedData), 0);

    printf("Data transmitted successfully.\n");

    close(sockfd);

    return 0;
}