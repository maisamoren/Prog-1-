#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "lib_inicio.h"


// void entrada (){
    // printw ("\n\n   DE-BURGER - O JOGO   \n\n");
    // printw ("Para começar o jogo, é preciso entrar com um número de pedidos.\n");
    // printw ("Digite um número: ");
// }

// void saida (){
    // printw ("\n\nMuito obrigada por jogar!\n\nTchau =)\n\n");
// }

// void menu (){
    // printw("\nPara jogar use as teclas:\n");
    // printw("     w - cima\n");
    // printw("     s - baixo\n");
    // printw("     a - esquerda\n");
    // printw("     d - direita\n");
    // printw("Aperte ' s ' para começar\n");
    // printw("Ou aperte ' q ' para sair\n");
// }

int bordas (int i, int j){
    if (i == 0){
        if ((j==0) || (j == COL-1))
            return 0;
    }
    if (i == LIN-1){
        if ((j==0) || (j == COL-1))
            return 0;
    }
    
    return 1;
}

int teto (int i, int j){
    if ((i==0) || (i == LIN-1)){
        if (bordas(i, j) == 1)
            return 0;
    }
    return 1;
}

int lado (int i, int j){
    if ((j==0) || (j == COL-1)){
        if (bordas(i, j) == 1)
            return 0;
    }
    return 1;
}

char** fazer_mapa (){
    char **mapa;

    mapa = (char**) malloc(LIN *sizeof(char*));
    for(int i = 0; i < LIN; i++){
        mapa[i] = (char*) malloc(COL *sizeof(char));  
        for(int j = 0; j < COL; j++){

            mapa[i][j] = VAZIO;

            if (bordas(i, j) == 0){
                mapa[i][j] = BORDA;
            }
            if (teto(i, j) == 0)
                mapa[i][j] = PAREDESI;
            if (lado(i, j) == 0)
                mapa[i][j] = PAREDEL;
        }
    }

    mapa[0][10] = ENTREGA;
    mapa[0][9] = PAREDEL;
    mapa[0][11] = PAREDEL;
    mapa[2][3] = REFRI;
    mapa[3][3] = FRITAS;
    mapa[5][5] = PBAIXO;
    mapa[5][8] = HAMBURGER;
    mapa[5][11] = QUEIJO;
    mapa[5][14] = SALADA;
    mapa[5][17] = PCIMA;    
    mapa[1][18] = LIXO;

     for(int i = 0; i < LIN;i++){
        for(int j = 0; j < COL; j++)
        mvaddch(i+9, j+8, mapa[i][j]);
    }

    refresh();

    return mapa;
}

void colocar_chapeiro_mapa (char **mapa, COORDENADAS *chapeiro){

    mapa[chapeiro->x][chapeiro->y]= CHAPEIRO;

    // mvaddch(chapeiro->x+9, chapeiro->y+8, CHAPEIRO);

    // refresh();
}

void imprime(char **mapa){

    for(int i = 0; i < LIN;i++){
        for(int j = 0; j < COL; j++)
        mvaddch(i+9, j+8, mapa[i][j]);
    }

    // refresh();
}