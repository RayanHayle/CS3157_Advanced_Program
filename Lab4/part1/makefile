CC = gcc
CFLAGS = -g -Wall -I../../lab3/solutions_part1
LDFLAGS = -L../../lab3/solutions_part1
LDLIBS =-lmylist

mdb-lookup:  mdb-lookup.o


mdb-lookup.o: mdb.h


.PHONY: clean

clean:
	rm -f *.o a.out mdb-lookup

.PHONY: all

all: clean mdb-lookup

.PHONY: valgrind

valgrind:
	valgrind --leak-check=yes ./mdb-lookup ap-mdb
 
