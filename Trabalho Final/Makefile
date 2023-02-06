CFLAGS = -Wall -g -std=c99

all: TrabFinal

TrabFinal: TrabFinal.o LibJogo.o 
	gcc $(CFLAGS) TrabFinal.o LibJogo.o -o TrabFinal

LibJogo.o: LibJogo.c LibJogo.h
	gcc $(CFLAGS) -c LibJogo.c


TrabFinal.o : TrabFinal.c 
	gcc $(CFLAGS) -c TrabFinal.c

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf TrabFinal