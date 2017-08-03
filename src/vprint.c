/*
 * vprint.c - part of c-sockets
 * Written by Martijn (MrTijn/Tijndagamer)
 * Copyright (c) 2017
 * Released under the MIT license
 */

#include "vprint.h"

int vprint(bool v, const char *format, ...)
{
    if (v) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}
