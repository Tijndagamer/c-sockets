/*
 * client.c - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#include "client.h"

int client(char *port, char *host, bool verbose)
{
    int sockfd, n;
    struct sockaddr_in s_addr;
    struct hostent *server;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(host, port, &hints, &res) != 0)
        error(1, "Error resolving host information\n");

    vprint(verbose, "Opening socket\n");
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0)
        error(1, "Error opening socket");

    printf("Connecting to %s:%s...", host, port);
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0)
        error(1, "Could not connect to %s", host);
    printf("done.\n");

    char buffer[256];
    bzero(buffer, 256);
    printf("> ");
    fgets(buffer, 255, stdin);

    if (write(sockfd, buffer, strlen(buffer)) < 0)
        error(1, "Error writing to socket");
    close(sockfd);
    printf("Connection closed.\n");
}
