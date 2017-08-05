CC = gcc
VPATH = src
CFLAGS = -I include
SRC = src/
HEADERS = $(wildcard include/*.h)
SRC = $(wildcard src/*.c)
OBJ = c-sockets.o client.o server.o util.o
EXEC = c-sockets

all : ll
%.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS)
ll : $(OBJ) $(HEADERS)
	$(CC) -o $(EXEC) $(OBJ)

debug :
	$(CC) -o $(EXEC) $(CFLAGS) -g $(SRC)

.PHONY : clean
clean :
	-rm $(EXEC) $(OBJ)

run : ll
	./c-sockets

