CC=gcc
CFLAGS=-std=gnu99 -g -pedantic -Wall -Wextra

conway: conway.h conway.h main.c
	$(CC) $(CFLAGS) -o main conway.c main.c

test: conway
	valgrind --leak-check=full --show-reachable=yes ./main

clean:
	rm -f *.o main
