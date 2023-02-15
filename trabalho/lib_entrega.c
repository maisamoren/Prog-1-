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

t_queue *verificaPedido(t_queue *clientes, t_pilha *burger, int *vidas, int *pontos) {

    t_queue *aux, *cliente;
    t_pilha *auxb;
  
    char icli, ibur;
    int flag=0;

    auxb = burger;
    aux = clientes;
    cliente = aux;

    FILE *p;
    p = fopen("teste.txt", "a");


    // testar o tamanho0
    if(auxb->topo != cliente->burg->topo){
        flag=1;
    }else{
        // testar os ingredientes
        for (int i = burger->topo; i >= 0; i--) {
            //fprintf(p, "[A]\n");
            pop(cliente->burg, &icli);
            pop(auxb, &ibur);
            if(icli!=ibur){
                flag = 1;
                
            }
            fprintf(p, "[%c] [%c]\n", ibur,icli);
        }
    }
    
    if(flag == 1){
        (*vidas)--;
        //fazer trecho de codigo que mexe na fila
        mvprintw (13, 3, "VIDAS: %d", *vidas);
        clientes = dequeue(aux);
        //mexer com as pilhas
        destroiRefeicao(burger);
    } else {
        clientes = dequeue(aux);
        *pontos = *pontos + 100;
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
    return clientes;
}

void destroiRefeicao(t_pilha *burger) {
    destroi_pilha(burger);
    burger = incializaPilha();
}