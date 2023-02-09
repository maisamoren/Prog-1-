#ifndef __LIB_INICIO__
#define __LIB_INICIO__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define LIN 7
#define COL 21
#define BORDA '#'
#define PAREDEL '|'
#define PAREDESI '-'
#define VAZIO ' '
#define ENTREGA '@'
#define CHAPEIRO '&'
#define LIXO 'o' 
#define HAMBURGER 'H' 
#define PBAIXO 'p'
#define PCIMA 'P'
#define QUEIJO 'Q'
#define SALADA 'S' 
#define FRITAS 'F' 
#define REFRI 'R'
#define CHAPEIRO_X_INIT 2
#define CHAPEIRO_Y_INIT 10

typedef struct coordenadas{
    int x, //linhas
        y; //colunas
}COORDENADAS;

int bordas (int i, int j);

int teto (int i, int j);

int lado (int i, int j);

char** fazer_mapa ();

void colocar_chapeiro_mapa (char **mapa, COORDENADAS *chapeiro);

void imprime(char **mapa);

#endif