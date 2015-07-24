/* 
 * File:   main.c
 * Author: James
 * Socket Client
 * Created on July 24, 2015, 10:47 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>


/*
 * 
 */
int main(int argc, char** argv) {
    int client = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    inet_aton("10.101.2.86", &server.sin_addr);
    server.sin_port = htons(2015);
    
    connect(client, (struct sockaddr *)&server, sizeof(server));
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    read(client, buffer, sizeof(buffer)-1);
    close(client);
    printf("%s\n", buffer);

    return (EXIT_SUCCESS);
}

