#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IP address from string to binary form
    if (inet_pton(AF_INET, "172.16.53.113", &server_address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    // Send data to the server
    const char* message = "Hello from the client!";
    send(client_socket, message, strlen(message), 0);

    // Receive response from the server
    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }

    printf("Received from server: %s\n", buffer);

    // Close socket
    close(client_socket);

    return 0;
}