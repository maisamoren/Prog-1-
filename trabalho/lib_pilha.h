#ifndef __LIB_PILHA__
#define __LIB_PILHA__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

// struct nó
typedef struct{
    char ingr;
    struct t_item *anterior;
} t_item;

// struct pilha
typedef struct {
    t_item *topo;
    t_item *prox;
} t_pilha;

t_pilha *incializaPilha ();

int pilhaVazia (t_pilha *burger);

void push(t_pilha *burger, char ingrediente);

void pop(t_pilha *burger);

#endif