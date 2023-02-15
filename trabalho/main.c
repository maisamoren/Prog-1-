#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib_entrega.h"
#include "lib_fila.h"
#include "lib_inicio.h"
#include "lib_legenda.h"
#include "lib_move.h"
#include "lib_pilha.h"

int main(int argc, char **argv) {

	int vidas = 14;
	int lixo = 10;
	int pontos = 0;

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

	entrada();

	clientes = incializaFila();
	regra();
	// scanw("%d", &num_clientes);
	num_clientes = 10;
	preenche_clientes(clientes, &num_clientes);
	
	clientes = dequeue(clientes);
	
	clear();
	refresh();
	burger = incializaPilha();

	mapa = fazer_mapa();

	int movimento;

	colocar_chapeiro_mapa(mapa, &chapeiro);
	imprime(mapa, vidas, lixo, pontos);
	menu(vidas, lixo, pontos);
	getch();

	// mexer o chapeiro no mapa
	while (movimento != 'Q' && vidas != 0 && lixo != 0 && clientes!= NULL) {
		clear();

		refresh();
		imprime_pilha(burger);

		imprime(mapa, vidas, lixo, pontos);
		imprime_fila(clientes);

		movimento = getch();

		if (movimento == KEY_UP) {
			// clear();
			clientes = movimenta_up(mapa, &chapeiro, burger, clientes, &vidas, &pontos);
			// imprime(mapa, vidas, lixo);
			// imprime_fila(clientes);
			// imprime_pilha(burger);
			// menu(vidas, lixo);
			// refresh();
		} else if (movimento == KEY_DOWN) {
			// clear();
			movimenta_down(mapa, &chapeiro, burger);
			// imprime(mapa, vidas, lixo);
			// imprime_fila(clientes);
			// imprime_pilha(burger);
			// menu(vidas, lixo);
			// refresh();
		} else if (movimento == KEY_LEFT) {
			// clear();
			movimenta_esq(mapa, &chapeiro, burger);
			// imprime(mapa, vidas, lixo);
			// imprime_fila(clientes);
			// imprime_pilha(burger);
			// menu(vidas, lixo);
			// refresh();
		} else if (movimento == KEY_RIGHT) {
			// clear();
			movimenta_dir(mapa, &chapeiro, burger, &lixo);
			// imprime(mapa, vidas, lixo);
			// imprime_fila(clientes);
			// imprime_pilha(burger);
			// menu(vidas, lixo);
			// refresh();
		}
		imprime(mapa, vidas, lixo, pontos);
		//imprime_fila(clientes);
		imprime_pilha(burger);
		menu(vidas, lixo, pontos);

    // CONFIRMAR SE O PEDIDO ESTÁ CORRETO
    // verificaPedido (clientes, burger, vidas);

    // contador do lixo
	
	}
	clear();
	refresh();

	if(clientes ==NULL){
		for(int  i =0; i <10;i++){
			mvprintw(10+i, 10, "Parabens");
		}
	}else if(vidas == 0 || lixo == 0 ){
		
		for(int  i =0; i <10;i++){
			mvprintw(10+i, 10, "GAme Over");
		}
		// imprime(mapa, vidas, lixo, pontos);
		// imprime_fila(clientes);
		// //imprime_fila(clientes);
		// imprime_pilha(burger);
		// menu(vidas, lixo, pontos);
	}
	movimento = getch();
	movimento = getch();
	movimento = getch();
	movimento = getch();
	movimento = getch();
	
	
	FILE *p;
    p = fopen("pont.txt", "w");
	fprintf(p, "[%d]\n", pontos);
	fclose(p);
	// para sair do jogo
	// saida ();

	// desaloca a memory & termina o ncurses
	refresh();

	getch();
	endwin();

	return 0;
}