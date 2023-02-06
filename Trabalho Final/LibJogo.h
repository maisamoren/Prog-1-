#ifndef __LibJogo__
#define __LibJogo__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct coordenadas{
    int x, //linhas
        y; //colunas
}COORDENADAS;

void entrada (int *p);

void saida ();

int bordas (int i, int j);

int teto (int i, int j);

int lado (int i, int j);

char** fazer_mapa ();

void colocar_chapeiro(COORDENADAS *chapeiro);

#endif