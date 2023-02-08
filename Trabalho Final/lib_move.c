#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "lib_inicio.h"
#include "lib_move.h"

int testa_mov_esq(char **mapa, COORDENADAS *chapeiro){

    if (mapa[chapeiro->x][(chapeiro->y)-1] == VAZIO)
        return 0;
    else
        return 1;
}

void movimenta_esq(char **mapa, COORDENADAS *chapeiro){

    int aux;

    if (testa_mov_esq(mapa,chapeiro)==1){
    // chapeiro n anda
        colocar_chapeiro_mapa (mapa, chapeiro);
    }

    else {
    // chapeiro andaa
        aux = (chapeiro->y)-1;
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->y = aux;
        colocar_chapeiro_mapa(mapa,chapeiro);
    }
}

int testa_mov_dir(char **mapa, COORDENADAS *chapeiro){

	if (mapa[chapeiro->x][(chapeiro->y)+1] == VAZIO)
        return 0;
    else
        return 1;
}

void movimenta_dir(char **mapa, COORDENADAS *chapeiro){

    int aux;

    if (testa_mov_dir(mapa,chapeiro)==1){
        colocar_chapeiro_mapa (mapa, chapeiro);
    }

    else {
        aux = (chapeiro->y)+1; // posicao nova
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->y = aux;
        colocar_chapeiro_mapa(mapa,chapeiro);
    }
}

int testa_mov_up(char **mapa, COORDENADAS *chapeiro){

	if (mapa[(chapeiro->x)-1][chapeiro->y] == VAZIO)
        return 0;
    else
        return 1;
}

void movimenta_up(char **mapa, COORDENADAS *chapeiro){

    int aux = 0;

    if (testa_mov_up(mapa,chapeiro)==1){
        colocar_chapeiro_mapa (mapa, chapeiro);
    }

    else {
        aux = (chapeiro->x)-1; // posicao nova
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->x = aux;
        colocar_chapeiro_mapa(mapa,chapeiro);
    }
}

int testa_mov_down(char **mapa, COORDENADAS *chapeiro){

	if (mapa[(chapeiro->x)+1][chapeiro->y] == VAZIO)
        return 0;
    else
        return 1;
}

void movimenta_down(char **mapa, COORDENADAS *chapeiro){

    int aux = 0;

    if (testa_mov_down(mapa,chapeiro)==1){
        colocar_chapeiro_mapa (mapa, chapeiro);
    }

    else {
        aux = (chapeiro->x)+1; // posicao nova
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->x = aux;
        colocar_chapeiro_mapa(mapa,chapeiro);
    }
}