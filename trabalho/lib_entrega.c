#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "lib_inicio.h"
#include "lib_fila.h"
#include "lib_pilha.h"

int soma (t_pilha *burger){

    int valor = 0;

    while(pilhaVazia(burger) == 0){

        if (burger->topo->ingr == PBAIXO){
            valor = valor + 1;
        } else if (burger->topo->ingr == HAMBURGER){
            valor = valor + 2;
        } else if (burger->topo->ingr == QUEIJO){
            valor = valor + 3;
        } else if (burger->topo->ingr == PCIMA){
            valor = valor + 4;
        } else if (burger->topo->ingr == SALADA){
            valor = valor + 5;
        } else if (burger->topo->ingr == FRITAS){
            valor = valor + 6;
        } else if (burger->topo->ingr == REFRI){
            valor = valor + 7;
        }

        pop(burger); 
    }

    return valor;
}

void verificaPedido (t_queue *clientes, t_pilha *burger, int *vidas){

    int valor;

    valor = soma (burger);

    if (clientes->somaPedido == valor){
        dequeue (clientes);
    }
    else {
        (*vidas)--;
        dequeue (clientes);
    }
}