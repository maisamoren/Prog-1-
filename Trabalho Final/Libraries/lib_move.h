#ifndef __LIB_MOVE__
#define __LIB_MOVE__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "lib_inicio.h"

int testa_mov_esq(char **mapa, COORDENADAS *chapeiro);

void movimenta_esq(char **mapa, COORDENADAS *chapeiro);

int testa_mov_dir(char **mapa, COORDENADAS *chapeiro);

void movimenta_dir(char **mapa, COORDENADAS *chapeiro);

#endif