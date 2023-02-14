#ifndef __LIB_PILHA__
#define __LIB_PILHA__

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#define MAX 100

struct pilha {
    int topo;
    char *ingr;
};
typedef struct pilha t_pilha;

t_pilha *incializaPilha ();

t_pilha *destroi_pilha (t_pilha *burger);

int pilhaVazia (t_pilha *burger);

int push(t_pilha *burger, char ingrediente);

int pop(t_pilha *burger, char *aux);

void imprime_pilha(t_pilha *burger);

#endif