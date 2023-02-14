#ifndef __LIB_FILA__
#define __LIB_FILA__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

// struct pilha
typedef struct {
    struct t_queue *prox;
    struct t_queue *anterior;
    int somaPedido;
} t_queue;

t_queue *incializaFila ();

void enqueue(t_queue *clientes, int somaPedido);

void dequeue (t_queue *clientes);

void preenche_clientes(t_queue *clientes, int *num_clientes);

void imprime_fila (t_queue *clientes);

#endif