/*                                                                             
 * c-sockets.c - part of c-sockets                                                
 * Written by Martijn (MrTijn/Tijndagamer)                                     
 * Copyright (c) 2017                                                          
 * Released under the MIT license                                              
 */

#include "c-sockets.h"
#include "client.h"
#include "server.h"

int main(int argc, char *argv[])
{
    int opt, port;
    // TODO: This will probably cause issues later on, find a better solution.
    char host[256];
    
    while((opt = getopt(argc, argv, "m:p:h:")) != -1) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                break;
            case 'h':
                strcpy(host, optarg);
                break;
            case 'm':
                if (strcmp(optarg, "server") == 0) {
                    mode = SERVER;
                } else if (strcmp(optarg, "client") == 0) {
                    mode = CLIENT;
                } else {
                    mode = NONE;
                }
                break;
            default:
                error(-1, 0, "Usage: %s -m mode -p port [-h host]", argv[0]);
        }
    }

    switch (mode) {
        case CLIENT:
            client(port, host);
            break;
        case SERVER:
            server(port);
            break;
        default:
            error(-1, 0, "Usage %s -m mode -p port [-h host]", argv[0]);
    }
}
