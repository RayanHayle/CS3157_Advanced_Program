CC = gcc
CFLAGS = -g -Wall -Wpedantic -std=c17


main:  main.o gcd.o prime.o
	$(CC) main.o gcd.o prime.o -o main


gcd.o: gcd.c gcd.h
	$(CC) -c $(CFLAGS) gcd.c



prime.o: prime.c prime.h
	$(CC) -c $(CFLAGS) prime.c



main.o: main.c gcd.h prime.h
	$(CC) -c  $(CFLAGS) main.c



.PHONY: clean

clean:
	rm -f *o. main

.PHONY: all

all:
	clean main
 
