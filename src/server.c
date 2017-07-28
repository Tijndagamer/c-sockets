/*
 * server.c - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#include "server.h"

int main(int argc, char *argv[])
{
    if (argc > 1) {
        printf("Starting server on port %s\n", argv[1]);
        server(atoi(argv[1]));
    } else {
        error(-1, 0, "Not enough arguments. Usage: %s port", argv[0]);
    }
}

int server(int port)
{
    int sockfd, conn_sockfd;
    int client_len;
    int n;
    char buffer[256];
    struct sockaddr_in s_addr, cl_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error(-1, 0, "Error opening socket");

    bzero((char *) &s_addr, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0)
        error(-1, 0, "Error binding name to socket");

    listen(sockfd, 5);

    while (1) {
        bzero(buffer, 256);
        client_len = sizeof(cl_addr);

        conn_sockfd = accept(sockfd, (struct sockaddrr *) &cl_addr, &client_len);
        if (conn_sockfd < 0)
            error(-1, 0, "Error accepting connection");
        // inet_ntoa converts the binary address to a user-presentable string
        printf("Accepted connection from %s:%d\n", inet_ntoa(cl_addr.sin_addr), cl_addr.sin_port);

        n = read(conn_sockfd, buffer, 255);
        printf("%s", buffer);

        close(conn_sockfd);
        printf("Connection closed\n");
    }
}
