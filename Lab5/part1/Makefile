cc = gcc
CFLAGS = -g -Wall -Wpedantic -std=c99

all: mdb-lookup-server-nc-1 mdb-lookup-server-nc-2



mdb-lookup-server-nc-1: mdb-lookup-server-nc-1.o
	$(CC) mdb-lookup-server-nc-1.o -o mdb-lookup-server-nc-1

mdb-lookup-server-nc-1.o: mdb-lookup-server-nc-1.c
	$(CC) -c $(CFLAGS) mdb-lookup-server-nc-1.c



mdb-lookup-server-nc-2: mdb-lookup-server-nc-2.o
	$(CC) mdb-lookup-server-nc-2.o -o mdb-lookup-server-nc-2

mdb-lookup-server-nc-2.o: mdb-lookup-server-nc-2.c
	$(CC) -c $(CFLAGS) mdb-lookup-server-nc-2.c



clean:
	rm -f *.o  mdb-lookup-server-nc-1 mdb-lookup-server-nc-2

.PHONY: all clean


