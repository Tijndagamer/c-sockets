/*
 * c-sockets.h - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#ifndef CSOCKETS_h
#define CSOCKETS_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum { NONE, SERVER, CLIENT } mode;

int main(int argc, char *argv[]);

#endif
