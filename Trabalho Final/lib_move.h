#ifndef __LIB_MOVE__
#define __LIB_MOVE__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "lib_inicio.h"
#include "lib_pilha.h"
#include "lib_entrega.h"

void movimenta_esq(char **mapa, COORDENADAS *chapeiro, t_pilha *burger);

void movimenta_dir(char **mapa, COORDENADAS *chapeiro, t_pilha *burger);

void movimenta_up(char **mapa, COORDENADAS *chapeiro, t_pilha *burger, t_queue *clientes, int *vidas);

void movimenta_down(char **mapa, COORDENADAS *chapeiro, t_pilha *burger);

#endif