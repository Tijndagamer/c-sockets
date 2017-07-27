CC = gcc
VPATH = src
CFLAGS = -I include
SRC = src/

client:
	$(CC) $(CFLAGS) -o client $(SRC)client.c

server:
	$(CC) $(CFLAGS) -o server $(SRC)server.c
all: client server
clean:
	$(RM) server client
