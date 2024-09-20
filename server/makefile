.PHONY: all clean

all: server.o
			$(CC) server.o -o server

server.o: server.c
			$(CC) -g -O1 -c server.c -Wall -Werror

clean:
		rm -f *.o server