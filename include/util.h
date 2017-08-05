/*
 * vprint.h - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#ifndef VPRINT_h
#define VPRINT_h

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

int vprint(bool v, const char *format, ...);
void error(int status, const char *format, ...);

#endif
