#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "lib_inicio.h"
#include "lib_move.h"

int testa_mov_esq(char **mapa, COORDENADAS *chapeiro){

    if ((mapa[chapeiro->x][chapeiro->y-1] == PAREDEL) || (mapa[chapeiro->x][chapeiro->y-1] == LIXO))
        return 1;
    if ((mapa[chapeiro->x][chapeiro->y-1] == HAMBURGER) || (mapa[chapeiro->x][chapeiro->y-1] == PBAIXO))
        return 1;
    if ((mapa[chapeiro->x][chapeiro->y-1] == PCIMA) || (mapa[chapeiro->x][chapeiro->y-1] == QUEIJO))
        return 1;
    if ((mapa[chapeiro->x][chapeiro->y-1] == SALADA) || (mapa[chapeiro->x][chapeiro->y-1] == FRITAS))
        return 1;
    if (mapa[chapeiro->x][chapeiro->y-1] == REFRI)
        return 1;

    else
        return 0;
}

void movimenta_esq(char **mapa, COORDENADAS *chapeiro){

    if (testa_mov_esq(mapa,chapeiro)==1){

        colocar_chapeiro_mapa (mapa, chapeiro);
    }

    else {
    // tira o chapeiro da posição antiga
        mapa[chapeiro->x][chapeiro->y--] = VAZIO;
        chapeiro->y-1;
        colocar_chapeiro_mapa (mapa, chapeiro);
    }
}

int testa_mov_dir(char **mapa, COORDENADAS *chapeiro){

    if ((mapa[chapeiro->x][chapeiro->y+1] == PAREDEL) || (mapa[chapeiro->x][chapeiro->y+1] == LIXO))
        return 1;
    if ((mapa[chapeiro->x][chapeiro->y+11] == HAMBURGER) || (mapa[chapeiro->x][chapeiro->y+1] == PBAIXO))
        return 1;
    if ((mapa[chapeiro->x][chapeiro->y+1] == PCIMA) || (mapa[chapeiro->x][chapeiro->y+1] == QUEIJO))
        return 1;
    if ((mapa[chapeiro->x][chapeiro->y+1] == SALADA) || (mapa[chapeiro->x][chapeiro->y+1] == FRITAS))
        return 1;
    if (mapa[chapeiro->x][chapeiro->y+1] == REFRI)
        return 1;
        
    else
        return 0;
}

void movimenta_dir(char **mapa, COORDENADAS *chapeiro){

    if (testa_mov_dir(mapa,chapeiro)==1){

        colocar_chapeiro_mapa (mapa, chapeiro);
    }

    else {
    // tira o chapeiro da posição antiga
        mapa[chapeiro->x][chapeiro->y++] = VAZIO;
        chapeiro->y+1;
        colocar_chapeiro_mapa (mapa, chapeiro);
    }
}