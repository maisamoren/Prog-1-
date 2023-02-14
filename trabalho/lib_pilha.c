#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "lib_pilha.h"

// FUNCOES DA PILHA 
t_pilha *incializaPilha (){
    t_pilha *burger;
    burger = malloc(sizeof(t_pilha));
    burger->topo = NULL;
    return burger;
}

int pilhaVazia (t_pilha *burger){
    if (burger->topo != NULL)
        return 0;
    return 1;
}

void push(t_pilha *burger, char ingrediente){
    t_item *novoItem = malloc(sizeof(t_item));
    novoItem->ingr = ingrediente;
    novoItem->anterior = NULL;

    if(burger->topo == NULL){
        burger->topo = novoItem;

        return;
    }

    novoItem->anterior = burger->topo;
    burger->topo = novoItem;
}

void pop(t_pilha *burger){
    t_item* aux = NULL;

    if(burger->topo == NULL){
        printf("PILHA VAZIA!!!!!");
        return;
    }

    aux = burger->topo;
    burger->topo = aux->anterior;

    free(aux);
    aux = NULL;
}