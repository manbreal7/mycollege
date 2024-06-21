#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345

int checkParity(int receivedData) {
    int count = 0;
    int temp = receivedData;

    while (temp) {
        count += temp & 1;
        temp >>= 1;
    }

    return (count % 2 == 0) ? 0 : 1;
}

int main() {
    int sockfd, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    int receivedData;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error binding socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    printf("Waiting for the sender to connect...\n");

    addr_size = sizeof(clientAddr);
    newSocket = accept(sockfd, (struct sockaddr*)&clientAddr, &addr_size);
    if (newSocket == -1) {
        perror("Error accepting connection");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Sender connected. Receiving data...\n");

    recv(newSocket, &receivedData, sizeof(receivedData), 0);

    int parityError = checkParity(receivedData);

    if (parityError) {
        printf("Error detected: Parity mismatch\n");
    } else {
        printf("Data received successfully: %d\n", receivedData);
    }

    close(newSocket);
    close(sockfd);

    return 0;
}