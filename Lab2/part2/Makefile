CC = gcc
CFLAGS = -g -Wall -Wpedantic -std=c17

twecho: twecho.o
	$(CC) twecho.o -o twecho

twecho.o: twecho.c
	$(CC) -c $(CFLAGS) twecho.c


.PHONY: clean

clean:
	rm -f *.o a.out core twecho


.PHONY: all

all:
	clean twecho      
