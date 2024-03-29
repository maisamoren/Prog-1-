#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib_entrega.h"
#include "lib_inicio.h"
#include "lib_legenda.h"
#include "lib_move.h"
#include "lib_pilha.h"

void movimenta_esq(char **mapa, COORDENADAS *chapeiro, t_pilha *burger) {
    int aux;
    int prox_bloco = mapa[chapeiro->x][(chapeiro->y) - 1];

    if (prox_bloco == VAZIO) {
    // chapeiro n anda
        aux = (chapeiro->y) - 1;
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->y = aux;
    } else if (prox_bloco == HAMBURGER || prox_bloco == PBAIXO ||
               prox_bloco == PCIMA || prox_bloco == QUEIJO ||
               prox_bloco == SALADA || prox_bloco == FRITAS ||
               prox_bloco == REFRI) {
        push(burger, prox_bloco);
    }

    colocar_chapeiro_mapa(mapa, chapeiro);
}

void movimenta_dir(char **mapa, COORDENADAS *chapeiro, t_pilha *burger, int *lixo) {
    int aux;
    int prox_bloco = mapa[chapeiro->x][(chapeiro->y) + 1];

    if (prox_bloco == VAZIO) {
        aux = (chapeiro->y) + 1; // posicao nova
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->y = aux;
    } else if (prox_bloco == HAMBURGER || prox_bloco == PBAIXO ||
               prox_bloco == PCIMA || prox_bloco == QUEIJO ||
               prox_bloco == SALADA || prox_bloco == FRITAS ||
               prox_bloco == REFRI) {
        push(burger, prox_bloco);
    } else if (prox_bloco == LIXO) {
        destroiRefeicao(burger);
        (*lixo)--;
        //mvprintw (x-2, y, "VIDAS: %d", vidas);
        mvprintw (13, 18, "LIXO: %d", *lixo); 
        // verificaPedido (clientes, burger, vidas);
    }

    colocar_chapeiro_mapa(mapa, chapeiro);
}

t_queue *movimenta_up(char **mapa, COORDENADAS *chapeiro, t_pilha *burger,
                  t_queue *clientes, int *vidas, int *pontos) {

    int aux = 0;
    int prox_bloco = mapa[(chapeiro->x) - 1][chapeiro->y];

    if (prox_bloco == VAZIO) {
        aux = (chapeiro->x) - 1; // posicao nova
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->x = aux;
    } else if (prox_bloco == ENTREGA) {
        clientes = verificaPedido(clientes, burger, vidas, pontos);
    } else if (prox_bloco == HAMBURGER || prox_bloco == PBAIXO ||
               prox_bloco == PCIMA || prox_bloco == QUEIJO ||
               prox_bloco == SALADA || prox_bloco == FRITAS ||
               prox_bloco == REFRI) {
        push(burger, prox_bloco);
    }

    colocar_chapeiro_mapa(mapa, chapeiro);
    return clientes;
}

void movimenta_down(char **mapa, COORDENADAS *chapeiro, t_pilha *burger) {
    int aux = 0;
    int prox_bloco = mapa[(chapeiro->x) + 1][chapeiro->y];

    if (prox_bloco == VAZIO) {
        aux = (chapeiro->x) + 1; // posicao nova
        mapa[chapeiro->x][chapeiro->y] = VAZIO;
        chapeiro->x = aux;
    } else if (prox_bloco == HAMBURGER || prox_bloco == PBAIXO ||
               prox_bloco == PCIMA || prox_bloco == QUEIJO ||
               prox_bloco == SALADA || prox_bloco == FRITAS ||
               prox_bloco == REFRI) {
        push(burger, prox_bloco);
    }

    colocar_chapeiro_mapa(mapa, chapeiro);
}