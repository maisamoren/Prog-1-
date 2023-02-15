#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib_fila.h"
#include "lib_inicio.h"
#include "lib_pilha.h"

int soma(t_pilha *burger) {

    int valor = 0;

    while (pilhaVazia(burger) == 0) {

    // if (burger->topo->ingr == PBAIXO){
    //     valor = valor + 1;
    // } else if (burger->topo->ingr == HAMBURGER){
    //     valor = valor + 2;
    // } else if (burger->topo->ingr == QUEIJO){
    //     valor = valor + 3;
    // } else if (burger->topo->ingr == PCIMA){
    //     valor = valor + 4;
    // } else if (burger->topo->ingr == SALADA){
    //     valor = valor + 5;
    // } else if (burger->topo->ingr == FRITAS){
    //     valor = valor + 6;
    // } else if (burger->topo->ingr == REFRI){
    //     valor = valor + 7;
    // }

    // pop(burger);
    }

    return valor;
}

void verificaPedido(t_queue *clientes, t_pilha *burger, int *vidas) {

    t_queue *aux, *cliente;
    t_pilha *auxb;
  
    char icli, ibur;
    int flag=0;

    auxb = burger;
    aux = clientes;
    cliente = aux->prox;

    FILE *p;
    char *str = "teste.txt";
    p = fopen("teste.txt", "a");

    for (int i = burger->topo; i >= 0; i--) {
        fprintf(p, "[A]\n");
        pop(cliente->burg, &icli);
        pop(auxb, &ibur);
        if(icli!=ibur){
            flag = 1;
        }
        fprintf(p, "[%c] [%c]\n", ibur,icli);
    }

    if(flag ==1){
        vidas--;
        //fazer trecho de codigo que mexe na fila

    } else {

    }

    fclose(p);
    // int valor;

    // valor = soma (burger);

    // if (clientes->somaPedido == valor){
    //     dequeue (clientes);
    // }
    // else {
    //     (*vidas)--;
    //     dequeue (clientes);
    // }
}

void destroiRefeicao(t_pilha *burger) {
    destroi_pilha(burger);
    burger = incializaPilha();
}