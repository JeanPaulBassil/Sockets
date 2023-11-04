#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define MAXLINE 4096
#define BACKLOG 10
#define SERVER_PORT 5554

int main(int argc, char* argv[]){
    int clientSocket;
    struct sockaddr_in servAddr;

    // Check for correct usage
    if(argc != 2){
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    // Create the socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0){
        perror("Socket Error");
        exit(1);
    }

    // Set the address family and port for the server address
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);

    // Convert the IP address from text to binary form
    if(inet_pton(AF_INET, argv[1], &servAddr.sin_addr) <= 0){
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    // Establish a connection to the server
    if(connect(clientSocket, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0){ // Corrected argument
        perror("Connection Error");
        exit(1);
    }

    char message[] = "hello";
    char message2[1024] = {0};

    int temp;

    send(clientSocket, message, strlen(message), 0);
    recv(clientSocket, message2, sizeof(message2), 0);
    printf("Received: %s\n", message2);

    close(clientSocket);
    return 0;
}
