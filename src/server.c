/*
 * server.c - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#include "server.h"

int server(int port, bool verbose)
{
    int sockfd, conn_sockfd;
    int client_len;
    int n;
    char buffer[256];
    char cl_ip[INET_ADDRSTRLEN];
    struct sockaddr_in s_addr, cl_addr;

    printf("starting c-socket server...\n");
    vprint(verbose, "opening socket...\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error(-1, 0, "error opening socket");

    bzero((char *) &s_addr, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    s_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0)
        error(-1, 0, "error binding name to socket");

    vprint(verbose, "listening...\n");
    listen(sockfd, 5);

    while (1) {
        bzero(buffer, 256);
        client_len = sizeof(cl_addr);

        vprint(verbose, "accepting connection...\n");
        conn_sockfd = accept(sockfd, (struct sockaddrr *) &cl_addr, &client_len);
        if (conn_sockfd < 0)
            error(-1, 0, "error accepting connection");
        inet_ntop(AF_INET, &(cl_addr.sin_addr), cl_ip, INET_ADDRSTRLEN);
        printf("accepted connection from %s:%d\n", cl_ip, cl_addr.sin_port);

        n = read(conn_sockfd, buffer, 255);
        printf("%s\n", buffer);

        close(conn_sockfd);
        printf("connection closed\n");
    }
}
