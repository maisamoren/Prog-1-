#ifndef _LIB_FILA_
#define _LIB_FILA_

#include "lib_pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

// struct pilha
typedef struct t_queue{
    struct t_queue *prox;
    struct t_queue *anterior;
    int somaPedido;
    char *ingr;
    t_pilha *burg;
} t_queue ;

t_queue *incializaFila ();

void enqueue(t_queue *clientes, int somaPedido);

void dequeue (t_queue *clientes);

void preenche_clientes(t_queue *clientes, int *num_clientes);

void imprime_fila (t_queue *clientes);

#endif