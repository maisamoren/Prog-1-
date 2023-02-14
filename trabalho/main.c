#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "lib_inicio.h"
#include "lib_move.h"
#include "lib_legenda.h"
#include "lib_pilha.h"
#include "lib_fila.h"
#include "lib_entrega.h"


int main (int argc, char **argv) {

    int vidas = 3;
    char **mapa;
    COORDENADAS chapeiro;
    t_pilha *burger;
    t_queue *clientes;
    int num_clientes;

// para iniciar o programa/jogo
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);

    chapeiro.x = CHAPEIRO_X_INIT;
    chapeiro.y = CHAPEIRO_Y_INIT;

    entrada ();

    clientes = incializaFila();
    menu();
    scanw("%d", &num_clientes);
    preenche_clientes(clientes, &num_clientes);

    clear();
    refresh();
    burger = incializaPilha();
    
    mapa = fazer_mapa ();

    int movimento;
    
    colocar_chapeiro_mapa (mapa, &chapeiro);
    imprime(mapa, vidas);
    pedidos (vidas);
    getch();

// mexer o chapeiro no mapa 
	while (movimento != 'Q' || vidas == 0){
		clear();

        refresh();
        imprime_pilha(burger);
        imprime(mapa, vidas);
        imprime_fila (clientes);

        movimento = getch();

        if (movimento == KEY_UP){
            clear();
			movimenta_up (mapa, &chapeiro, burger, clientes, &vidas);
			imprime(mapa, vidas);
            imprime_fila (clientes);
            imprime_pilha(burger);
            pedidos (vidas);
			refresh();
        } else if (movimento == KEY_DOWN){
            clear();
			movimenta_down (mapa, &chapeiro, burger);
			imprime(mapa, vidas);
            imprime_fila (clientes);
            imprime_pilha(burger);
            pedidos (vidas);
			refresh();
        } else if (movimento == KEY_LEFT){
            clear();
			movimenta_esq (mapa, &chapeiro, burger);
			imprime(mapa, vidas);
            imprime_fila (clientes);
            imprime_pilha(burger);
            pedidos (vidas);
			refresh();
        } else if (movimento == KEY_RIGHT){
            clear();
			movimenta_dir (mapa, &chapeiro, burger);
			imprime(mapa, vidas);
            imprime_fila (clientes);
            imprime_pilha(burger);
            pedidos (vidas);
			refresh();
        } 

        // CONFIRMAR SE O PEDIDO ESTÁ CORRETO
        // verificaPedido (clientes, burger, vidas);

        // contador do lixo

    }

// para sair do jogo
    //saida ();

// desaloca a memory & termina o ncurses
    refresh();
    
    getch();
    endwin();

    return 0;
}