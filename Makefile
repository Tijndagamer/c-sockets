CC = gcc
VPATH = src
CFLAGS = -I include
SRC = src/

client:
	$(CC) $(CFLAGS) -o client $(SRC)client.c

server:
	$(CC) $(CFLAGS) -o server $(SRC)server.c
clean:
	$(RM) server client
all: clean client server
