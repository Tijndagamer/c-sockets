/*
 * server.h - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#ifndef SERVER_h
#define SERVER_h

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <unistd.h>
#include <arpa/inet.h>

int server(int port);

#endif
