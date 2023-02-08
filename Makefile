CFLAGS = -Wall -g -std=c99

all: main

main: main.o lib_inicio.o lib_move.o
	gcc $(CFLAGS) main.o lib_inicio.o lib_move.o -o main -lncurses -ltinfo

lib_inicio.o: lib_inicio.c lib_inicio.h
	gcc $(CFLAGS) -c lib_inicio.c -lncurses -ltinfo

lib_move.o: lib_move.c lib_move.h
	gcc $(CFLAGS) -c lib_move.c -lncurses -ltinfo

main.o : main.c 
	gcc $(CFLAGS) -c main.c -lncurses -ltinfo

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf main