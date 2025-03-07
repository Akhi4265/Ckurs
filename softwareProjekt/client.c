#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Socket erstellen
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Fehler beim Erstellen des Sockets");
        exit(EXIT_FAILURE);
    }
    printf("Client-Socket erfolgreich erstellt\n");

    // Serveradresse setzen
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);  // Port muss zum Server passen!
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // = 127.0.0.1
    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

    // Verbindung zum Server herstellen
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Fehler beim Verbinden mit dem Server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Verbindung zum Server erfolgreich!\n");
    // nachricht senden
    char *message = "Hallo, Server!";
    send(sockfd, message, strlen(message), 0);
    printf("Nachricht gesendet: %s\n", message);
    
    
    // nachricht emfangen
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Fehler beim Empfangen der Daten");
    } else {
        printf("Antwort vom Server: %s\n", buffer);
    }

    // Verbindung schließen
    close(sockfd);
    return 0;
}
