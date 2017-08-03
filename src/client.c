/*
 * client.c - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#include "client.h"

int client(int port, char *host, bool verbose)
{
    int sockfd, n;
    struct sockaddr_in s_addr;
    struct hostent *server;

    // Prepare socket
    vprint(verbose, "opening socket\n");
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error(-1, 0, "error opening socket");

    // Prepare server information
    printf("Resolving hostname...");
    server = gethostbyname(host);
    if (server == NULL)
        error(-1, 0, "could not resolve hostname, or no such IP exists");
    printf("done.\n");

    bzero((struct sockaddr_in *) &s_addr, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);
    bcopy((char *)server->h_addr, (char *) &s_addr.sin_addr.s_addr, server->h_length);

    printf("connecting to %s:%d...", host, port);
    if (connect(sockfd, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0)
        error(-1, 0, "could not connect to %s", host);
    printf("done.\n");

    char buffer[256];
    bzero(buffer, 256);
    printf("> ");
    fgets(buffer, 255, stdin);

    if (write(sockfd, buffer, strlen(buffer)) < 0)
        error(-1, 0, "error writing to socket");
    close(sockfd);
    printf("connection closed.\n");
}
