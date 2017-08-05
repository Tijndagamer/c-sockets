/*
 * server.c - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#include "server.h"

int server(char *port, bool verbose)
{
    int sockfd, conn_sockfd;
    int client_len;
    int n;
    char buffer[256];
    char cl_ip[INET_ADDRSTRLEN];
    struct sockaddr_in cl_addr;
    struct addrinfo hints, *res;

    printf("Starting c-socket server...\n");

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // TODO: Add IPv6 support
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, port, &hints, &res) != 0)
        error(1, "Error getaddrinfo\n");

    vprint(verbose, "Opening socket...\n");
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
        error(1, "Error opening socket\n");

    if (bind(sockfd, res->ai_addr, res->ai_addrlen) < 0)
        error(1, "Error binding to socket\n");

    vprint(verbose, "Listening...\n");
    listen(sockfd, 5);

    while (1) {
        bzero(buffer, 256);
        client_len = sizeof(cl_addr);

        vprint(verbose, "Accepting connection...\n");
        conn_sockfd = accept(sockfd, (struct sockaddrr *) &cl_addr, &client_len);
        if (conn_sockfd < 0)
            error(-1, 0, "Error accepting connection");
        inet_ntop(AF_INET, &(cl_addr.sin_addr), cl_ip, INET_ADDRSTRLEN);
        printf("Accepted connection from %s:%d\n", cl_ip, cl_addr.sin_port);

        n = read(conn_sockfd, buffer, 255);
        printf("%s\n", buffer);

        close(conn_sockfd);
        printf("Connection closed\n");
    }
}
