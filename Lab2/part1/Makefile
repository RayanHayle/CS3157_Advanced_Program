CC = gcc
CFLAGS = -g -Wall -Wpedantic -std=c17


isort: isort.o
	$(CC) isort.o   -o isort

isort.o :  isort.c
	$(CC) -c $(CFLAGS) isort.c


.PHONY: clean

clean:
	rm -f *.o a.out core isort


.PHONY: all

all:
		clean isort
