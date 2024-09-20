# Makefile for lab 3, part 2

CC = gcc
CFLAGS = -g -Wall -I../solutions_part1
LDFLAGS = -L../solutions_part1
LDLIBS = -lmylist

revecho:

revecho.o:

#revecho: revecho.o
#	$(CC) $(LDFLAGS) -o revecho revecho.o -lmylist


#revecho.o: revecho.c
#	$(CC) $(CFLAGS) -c revecho.c

#mylist.o: ../solutions_part1/mylist.c
#	$(CC) -c ../solutions_part1/mylist.c -o mylist.o

.PHONY: clean
clean:
	rm -f *.o revecho #libmylist.a

.PHONY: all
all: clean revecho #libmylist.a 
