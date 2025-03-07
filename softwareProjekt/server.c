#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int sockfd, client_sock;
    struct sockaddr_in server_addr,client_addr;
    socklen_t client_size;

    sockfd = socket(AF_INET,SOCK_STREAM,0); // AF_INET = IPV4; SOCK_STREAM = TCP, SOCK_DGRAM = UDP; 0 über nimmt 2 paarmeter kann auch IPPROTO_TCP für SOCK_Stream oder IPPROTO_UDP für SOCK_DGRAM 
    if(sockfd == -1){
        perror("Fehler beim erstellen des Sockets");
        exit(1);
    }

    printf("Socket erfolgreich Erstellt\n");

    server_addr.sin_family = AF_INET;                 // IPv4 
    server_addr.sin_port = htons(8080);    // Portnummer
    server_addr.sin_addr.s_addr = INADDR_ANY;        // lauscht auf alle verffügbaren ip adressen 

    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
        perror("Bind-Fehler");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Socket wurde erfolgreich mit %d Port gebunden\n", ntohs(server_addr.sin_port));
    if (listen(sockfd,5) == -1){
        perror("Listen Fehler");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Server Lauscht auf Verbindungen ...\n");
    
    // client-Verbindungen akzeptieren
    client_size = sizeof(client_addr);
    client_sock = accept(sockfd, (struct sockaddr*)&client_addr, &client_size);

    if (client_sock == -1) {
        perror("Fehler beim Akzeptiern der Verbindung\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    char *message = "Hallo, Client!";
    send(client_sock,message,strlen(message),0);
    printf("nachricht an Client gesickt: %s\n",message);




    close(client_sock);
    close(sockfd);

    return 0;
}