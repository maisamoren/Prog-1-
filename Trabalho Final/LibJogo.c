#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "LibJogo.h"

#define LIN 6
#define COL 21
#define BORDA '#'
#define PAREDEL '|'
#define PAREDESI '-'
#define VAZIO ' '
#define ENTREGA '@'
#define CHAPEIRO '&'
#define LIXO 'o' 
#define HAMBURGER 'H' 
#define PBAIXO 'p'
#define PCIMA 'P'
#define QUEIJO 'Q'
#define SALADA 'S' 
#define FRITAS 'F' 
#define REFRI 'R'

void entrada (int *p){
    printf ("   DE-BURGER - O JOGO   \n");
    printf ("\n");
    
    printf ("Para começar o jogo, é preciso entrar com um número de pedidos.\n");
    printf ("Digite um número: ");
    scanf ("%d", p);

    printf ("\n\nO jogo será inicalizado agora .........\n");
}

void saida (){
    printf ("\n\nMuito obrigada por jogar!\n\nTchau =)\n\n");
}

int bordas (int i, int j){
    if (i == 0){
        if ((j==0) || (j == COL-1))
            return 0;
    }
    if (i == LIN-1){
        if ((j==0) || (j == COL-1))
            return 0;
    }
    
    // else 
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
            if (bordas(i, j) == 0)
                mapa[i][j] = BORDA; 
            if (teto(i, j) == 0)
                mapa[i][j] = PAREDESI;
            if (lado(i, j) == 0)
                mapa[i][j] = PAREDEL;
            else
                mapa[i][j] = VAZIO;
        }
    }

    mapa[0][10] = ENTREGA;
    mapa[2][3] = REFRI;
    mapa[3][3] = FRITAS;
    mapa[4][6] = PBAIXO;
    mapa[4][8] = HAMBURGER;
    mapa[4][10] = QUEIJO;
    mapa[4][12] = SALADA;
    mapa[4][14] = PCIMA;    
    mapa[2][18] = LIXO;

    return mapa;
}

void colocar_chapeiro(COORDENADAS *chapeiro){

    (*chapeiro).x = 2;
    (*chapeiro).y = 10;
}