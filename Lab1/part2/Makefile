CC = gcc
CFLAGS = -g -Wall -Wpedantic -std=c17


convert: convert.o
	$(CC) convert.o   -o convert

convert.o :  convert.c 
	$(CC) -c $(CFLAGS) convert.c


.PHONY: clean

clean:
	rm -f *.o a.out core myprogram


.PHONY: all

all:
	clean convert

