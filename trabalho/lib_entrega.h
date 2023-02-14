#ifndef __LIB_ENTREGA__
#define __LIB_ENTREGA__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "lib_fila.h"
#include "lib_pilha.h"

int soma (t_pilha *burger);

void verificaPedido (t_queue *clientes, t_pilha *burger, int *vidas);

#endif