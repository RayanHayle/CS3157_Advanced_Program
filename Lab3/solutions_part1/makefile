# Makefile for lab 3, part 1.

CC = gcc
CFLAGS = -g -Wall
LDFLAGS =
LDLIBS =

mylist-test: libmylist.a

libmylist.a: mylist.o
	ar rcs libmylist.a mylist.o

# header dependency
mylist-test.o: mylist.h
mylist.o: mylist.h

.PHONY: clean
clean:
	rm -f *.o libmylist.a mylist-test

.PHONY: all
all: clean libmylist.a mylist-test
