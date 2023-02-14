#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>

#include "lib_fila.h"

t_queue *incializaFila (){
    t_queue *clientes;
    clientes = malloc(sizeof(t_queue));

    clientes->prox = NULL;
    clientes->anterior = NULL;
    clientes->somaPedido = 0;
    return clientes;
}

void enqueue(t_queue *clientes, int somaPedido){
    t_queue *novoCliente = NULL;
    t_queue *aux = clientes;

    novoCliente = malloc(sizeof(t_queue));

    novoCliente->prox = NULL;
    novoCliente->somaPedido = somaPedido;

    if(aux->prox == NULL){
        aux->prox = novoCliente;
        novoCliente->anterior = aux;

        return;
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novoCliente;
    novoCliente->anterior = aux;
}

void dequeue (t_queue *clientes){
    t_queue *aux = clientes;

    if(aux->prox == NULL && aux->anterior == NULL){
        printf("FILA VAZIA");
        return;
    }

    clientes = aux->prox;
    clientes->anterior = NULL;

    free(aux);
    aux = NULL;
}

// p = 1, H = 2, Q = 3, P = 4, S = 5, F=6, R=7
void preenche_clientes(t_queue *clientes, int *num_clientes){

    time_t t;

    srand((unsigned) time(&t));

    for(int i=0;i<*num_clientes;i++){
        int pedido = rand() % 6;
        switch (pedido)
        {
        case 0:
            // [p]+[H]+[Q]+[P]
            enqueue(clientes, 10);
            break;
        case 1:
            //[p]+[H]+[S]+[P] 
            enqueue(clientes, 12);
            break;
        case 2:
            //[p]+[H]+[Q]+[P]+[F]+[R]
            enqueue(clientes, 23);
            break;
        case 3:
            //[p]+[H]+[S]+[P]+[F]+[R]
            enqueue(clientes, 25);
            break;
        case 4:
            //[p]+[Q]+[P]+[F]+[R]
            enqueue(clientes, 21);
            break;
        case 5:
            //[S]+[F]+[R]
            enqueue(clientes, 18);
            break;
        default:
            break;
        }
    }
}

void imprime_fila (t_queue *clientes){

    int x = 3;
    int y = 52;
    t_queue *aux;

    aux =  clientes;

    mvprintw (x-1, y, "FILA DE PEDIDOS:");

    while (aux){
        x++;
        if (aux->somaPedido == 10){
            mvprintw (x, y, "X-Burger");
        } else if (aux->somaPedido == 12){
            mvprintw (x, y, "X-Salada");
        } else if (aux->somaPedido == 23){
            mvprintw (x, y, "Combo 1");
        } else if (aux->somaPedido == 25){
            mvprintw (x, y, "Combo 2");
        } else if (aux->somaPedido == 21){
            mvprintw (x, y, "Vegetariano");
        } else if (aux->somaPedido == 18){
            mvprintw (x, y, "Vegano");
        }

        aux = aux->prox;
    }
}