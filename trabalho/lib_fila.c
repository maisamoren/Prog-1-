#include <curses.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lib_fila.h"
#include "lib_inicio.h"
#include "lib_pilha.h"

#define MAX 100

t_queue *incializaFila() {
    t_queue *clientes;
    clientes = malloc(sizeof(t_queue)); 

    clientes->prox = NULL;
    clientes->anterior = NULL;
    clientes->somaPedido = 0;
    clientes->ingr = malloc(sizeof(char) * MAX);
    clientes->burg = incializaPilha();

    return clientes;
}

void enqueue(t_queue *clientes, int somaPedido) {
    t_queue *novoCliente = NULL;
    t_queue *aux = clientes;

    novoCliente = malloc(sizeof(t_queue));

    novoCliente->prox = NULL;
    novoCliente->somaPedido = somaPedido;
    novoCliente->burg = incializaPilha();

    switch (somaPedido) {
        case 0:
            push(novoCliente->burg, PBAIXO);
            push(novoCliente->burg, HAMBURGER);
            push(novoCliente->burg, QUEIJO);
            push(novoCliente->burg, PCIMA);
            //[p]+[H]+[Q]+[P]
            break;
        case 1:
            push(novoCliente->burg, PBAIXO);
            push(novoCliente->burg, HAMBURGER);
            push(novoCliente->burg, SALADA);
            push(novoCliente->burg, PCIMA);
            //[p]+[H]+[S]+[P]
            break;
        case 2:
            push(novoCliente->burg, PBAIXO);
            push(novoCliente->burg, HAMBURGER);
            push(novoCliente->burg, QUEIJO);
            push(novoCliente->burg, PCIMA);
            push(novoCliente->burg, FRITAS);
            push(novoCliente->burg, REFRI);

            //[p]+[H]+[Q]+[P]+[F]+[R]
            break;
        case 3:
            push(novoCliente->burg, PBAIXO);
            push(novoCliente->burg, HAMBURGER);
            push(novoCliente->burg, SALADA);
            push(novoCliente->burg, PCIMA);
            push(novoCliente->burg, FRITAS);
            push(novoCliente->burg, REFRI);

            //[p]+[H]+[S]+[P]+[F]+[R]
            break;
        case 4:
            push(novoCliente->burg, PBAIXO);
            push(novoCliente->burg, QUEIJO);
            push(novoCliente->burg, PCIMA);
            push(novoCliente->burg, FRITAS);
            push(novoCliente->burg, REFRI);
            //[p]+[Q]+[P]+[F]+[R]
            break;
        case 5:
            push(novoCliente->burg, SALADA);
            push(novoCliente->burg, FRITAS);
            push(novoCliente->burg, REFRI);
            //[S]+[F]+[R]
            break;
        default:
            break;
    }

    if (aux->prox == NULL) {
        aux->prox = novoCliente;
        novoCliente->anterior = aux;
        return;
    }

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novoCliente;
    novoCliente->anterior = aux;
}

t_queue *dequeue(t_queue *clientes) {
    t_queue *aux = clientes;

    if (aux->prox == NULL && aux->anterior == NULL && clientes == NULL) {
        printw("FILA VAZIA");
        return;
    }

    clientes =  aux->prox;
    if(clientes != NULL){
        clientes->anterior = NULL;
    }

    free(aux);
    // aux = NULL;

    return clientes;
}

void preenche_clientes(t_queue *clientes, int *num_clientes) {

    time_t t;
    t_queue *aux = clientes;

    srand((unsigned)time(&t));

    for (int i = 0; i < *num_clientes; i++) {
        int pedido = rand() % 6;
        // int pedido = 0;
        enqueue(aux, pedido);
    }
    //dequeue(aux);
}

void imprime_fila(t_queue *clientes) {

    int x = 3;
    int y = 52;
    t_queue *aux;

    aux = clientes;

    mvprintw(x - 1, y, "FILA DE PEDIDOS:");

    while (aux) {
        x = x + 2;
        // x++;
        // [cliente 1 | Combo 1] ->
        if (aux->somaPedido == 0) {
            mvprintw(x, y, "X-Burger");
            mvprintw(x + 1, y, "%s", &aux->burg->ingr[0]);
        } else if (aux->somaPedido == 1) {
            mvprintw(x, y, "X-Salada");
            mvprintw(x + 1, y, "%s", &aux->burg->ingr[0]);
        } else if (aux->somaPedido == 2) {
            mvprintw(x, y, "Combo 1");
            mvprintw(x + 1, y, "%s", &aux->burg->ingr[0]);
        } else if (aux->somaPedido == 3) {
            mvprintw(x, y, "Combo 2");
            mvprintw(x + 1, y, "%s", &aux->burg->ingr[0]);
        } else if (aux->somaPedido == 4) {
            mvprintw(x, y, "Vegetariano");
            mvprintw(x + 1, y, "%s", &aux->burg->ingr[0]);
        } else if (aux->somaPedido == 5) {
            mvprintw(x, y, "Vegano");
            mvprintw(x + 1, y, "%s", &aux->burg->ingr[0]);
        }

        aux = aux->prox;
    }
}