// Included libraries for various functions and definitions
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<pthread.h>

// Definitions for buffer size, queue limit for pending connections, and server port
#define MAXLINE 4096
#define BACKLOG 10
#define SERVER_PORT 5554

// Function prototype declaration
void convertToUpper(char*);

// Function to convert string to uppercase
void convertToUpper(char* str){
    while (*str != '\0'){
        *str = toupper((unsigned char)*str);
        ++str;
    }
}

int main(){
    int serverSocket;
    int clientSocket;
    struct sockaddr_in servAddr; // Server address structure
    time_t ticks;
    int clientCounter = 0;

    // Creating a socket for the server
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0){
        perror("Socket Creation Failed.\n");
        exit(EXIT_FAILURE);
    }

    // Set server address structure fields
    servAddr.sin_family = AF_INET; // Address family
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Accept connections on any IP of the server
    servAddr.sin_port = htons(SERVER_PORT); // Server port to open

    // Binding the server socket to the specified IP and port
    if(bind(serverSocket, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0){
        perror("Binding Error.\n");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if(listen(serverSocket, BACKLOG) < 0){
        perror("Listen Error.\n");
        exit(EXIT_FAILURE);
    }
    
    // Server runs indefinitely
    while(1){
        // Accepting a new connection
        clientSocket = accept(serverSocket, NULL, NULL);
        if(clientSocket < 0){
            perror("Accept Error.\n");
            continue;
        }
        
        clientCounter++;
        
        // Buffer to store the message from the client
        char buffer[MAXLINE];
        int n = read(clientSocket, buffer, MAXLINE - 1);

        if(n < 0){
            perror("Reading Error.\n");
            continue; // Skip to next iteration if read error occurs
        }
        
        buffer[n] = '\0'; // Null terminate the string
        
        // Print the message from the client
        printf("Server Reads: %s\n", buffer);

        // Convert the message to uppercase
        convertToUpper(buffer);

        // Send the converted message back to the client
        if(write(clientSocket, buffer, strlen(buffer)) < 0){
            perror("Writing Error.\n");
        }

        // Close the connection with the client
        close(clientSocket);

        // Logging the connection with timestamp
        ticks = time(NULL);
        printf("Client %d connected at time %s\n", clientCounter, ctime(&ticks));
    }

    // Close the server socket and end the program
    close(serverSocket);
    return 0;
}
