#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "lib_inicio.h"
#include "lib_move.h"
#include "lib_legenda.h"

int main (int argc, char **argv) {

    int p;
    char **mapa;
    COORDENADAS chapeiro;

// para iniciar o programa/jogo
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);

    chapeiro.x = CHAPEIRO_X_INIT;
    chapeiro.y = CHAPEIRO_Y_INIT;

    entrada ();

    menu();

    scanw ("%d", &p); 
    clear();
    refresh();
    // printf p 
    
    mapa = fazer_mapa ();

    int movimento;
    
    colocar_chapeiro_mapa (mapa, &chapeiro);
    imprime(mapa);
    pedidos ();
    help ();

	while (movimento != 'Q'){
		clear();

        refresh();

        imprime(mapa);
        movimento = getch();

        if (movimento == KEY_UP){
            clear();
			movimenta_up (mapa, &chapeiro);
			imprime(mapa);
            pedidos ();
			refresh();
        } else if (movimento == KEY_DOWN){
            clear();
			movimenta_down (mapa, &chapeiro);
			imprime(mapa);
            pedidos ();
			refresh();
        } else if (movimento == KEY_LEFT){
            clear();
			movimenta_esq (mapa, &chapeiro);
			imprime(mapa);
            pedidos ();
			refresh();
        } else if (movimento == KEY_RIGHT){
            clear();
			movimenta_dir (mapa, &chapeiro);
			imprime(mapa);
            pedidos ();
			refresh();
        } else if (movimento == 'h'){
            help ();
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