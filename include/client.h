/*
 * client.h - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#ifndef CLIENT_h
#define CLIENT_h

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>
#include <netdb.h>
#include <unistd.h>
#include <stdbool.h>
#include "vprint.h"

int client(int port, char *host, bool verbose);

#endif
