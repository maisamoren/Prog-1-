#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
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

    int movimento;
    
    colocar_chapeiro_mapa (mapa, &chapeiro);
    imprime(mapa);

	while (1){
		movimento = getch();
			
		switch(movimento){

			printw ("\nentrou no switch");

			case (KEY_LEFT): //'a': 
				clear();
				testa_mov_esq (mapa, &chapeiro);
				movimenta_esq (mapa, &chapeiro);
				imprime(mapa);
				refresh();

			case (KEY_RIGHT): //'d':
				clear();
				testa_mov_dir (mapa, &chapeiro);
				movimenta_dir (mapa, &chapeiro);
				imprime(mapa);
				refresh();

			case (KEY_UP):  //'w':
				clear();
				testa_mov_up (mapa, &chapeiro);
				movimenta_up (mapa, &chapeiro);
				imprime(mapa);
				refresh();

			case (KEY_DOWN): //'s':
				clear();
				testa_mov_down (mapa, &chapeiro);
				movimenta_down (mapa, &chapeiro);
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