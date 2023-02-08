#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "lib_inicio.h"
#include "lib_move.h"

int main (int argc, char **argv) {

    int p;
    char **mapa;
    COORDENADAS chapeiro;

// para iniciar o programa/jogo
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    chapeiro.x = CHAPEIRO_X_INIT;
    chapeiro.y = CHAPEIRO_Y_INIT;

    // entrada ();
    printw ("\n\n      DE-BURGER - O JOGO   \n\n");

    //menu();
    printw("\n\nPara jogar use as teclas W, A, S e D.\n");
    printw("  Aperte 'C' para começar\n");
    printw("  Ou aperte 'Q' para sair\n");

    printw ("Para começar o jogo, é preciso entrar com um número de pedidos.\n");
    printw ("Digite um número: ");

    scanw ("%d", &p); 
    clear();
    refresh();
    // printw("p = %d", &p);
    
    mapa = fazer_mapa ();

    char movimento;
    
    colocar_chapeiro_mapa (mapa, &chapeiro);
    imprime(mapa);

	while (1){
		scanf ("%c", &movimento);
        // printw ("\nmmmmm%c",movimento);
			
		switch(movimento){

			// printw ("\nentrou no switch");

			case 'a': //(KEY_LEFT): 
				clear();
				movimenta_esq (mapa, &chapeiro);
	    		printw ("\n%c",movimento);
				imprime(mapa);
				refresh();

			case 'd': // (KEY_RIGHT): 
				clear();
				movimenta_dir (mapa, &chapeiro);
                printw ("\n%c",movimento);
				imprime(mapa);
				refresh();

			case 'w': // (KEY_UP): 
				clear();
				movimenta_up (mapa, &chapeiro);
                printw ("\n%c",movimento);
				imprime(mapa);
				refresh();

			case 's': //(KEY_DOWN):
				clear();
				movimenta_down (mapa, &chapeiro);
	    		printw ("\n%c",movimento);
				imprime(mapa);
				refresh();
    	}
    }

// para sair do jogo
    //saida ();
    printw ("\n\nMuito obrigada por jogar!\n\nTchau =)\n\n");
    
// desaloca a memory & termina o ncurses
    refresh();
    
    getch();
    endwin();

    return 0;
}