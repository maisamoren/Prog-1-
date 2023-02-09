#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

// #include "lib_inicio.h"
#include "lib_move.h"

void entrada (){
    printw ("\n\n   DE-BURGER - O JOGO   \n\n");
}

void saida (){
    printw ("\n\nMuito obrigada por jogar!\n\nTchau =)\n\n");
}

void menu (){
    printw("Para jogar use as setas do teclado.\n");
    printw("    Aperte 'Q' para sair do jogo\n");

    printw ("\nPara começar o jogo, é preciso entrar com um número de pedidos.\n");
    printw ("Digite um número: ");
}

void pedidos (){   

    int x = 15;
    int y = 3;

    mvprintw(x, y,    " -------------| OPCOES DE PEDIDOS |-------------");
    mvprintw(x+1, y,  " |                                             |");
    mvprintw(x+2, y,  " |  1. X-Burger       [p] [H] [Q] [P]          |");
    mvprintw(x+3, y,  " |  2. X-Salada       [p] [H] [S] [P]          |");
    mvprintw(x+4, y,  " |  3. Combo 1        [p] [H] [Q] [P] [F] [R]  |");
    mvprintw(x+5, y,  " |  4. Combo 2        [p] [H] [S] [P] [F] [R]  |");
    mvprintw(x+6, y,  " |  5. Vegetariano    [p] [Q] [P] [F] [R]      |");
    mvprintw(x+7, y,  " |  6. Vegano         [S] [F] [R]              |");
    mvprintw(x+8, y,  " |                                             |");
    mvprintw(x+9, y,  " -----------------------------------------------");
}

void help (){

    int x = 30;
    int y = 3;

    mvprintw(x, y,    " -------------------| LEGENDA |------------------- \n");
    mvprintw(x+1, y,  " |                                               | \n");
    mvprintw(x+2, y,  " |  &   ->  é o cozinhero                        | \n");
    mvprintw(x+3, y,  " |  @   ->  é o ponto de entrega dos pedidos     | \n");
    mvprintw(x+4, y,  " |  o   ->  é a lixeira                          | \n");
    mvprintw(x+5, y,  " |                                               | \n");
    mvprintw(x+6, y,  " |  R   ->  é a estação dos REFRIGERANTES        | \n");
    mvprintw(x+7, y,  " |  F   ->  é a estação das BATATAS FRITAS       | \n");
    mvprintw(x+8, y,  " |  p   ->  é a estação do pão (parte de BAIXO)  | \n");
    mvprintw(x+9, y,  " |  P   ->  é a estação do pão (parte de CIMA)   | \n");
    mvprintw(x+10, y, " |  Q   ->  é a estação do  QUEIJO               | \n");
    mvprintw(x+11, y, " |  S   ->  é a estação da SALADA                | \n");
    mvprintw(x+12, y, " |                                               | \n");
    mvprintw(x+13, y, " ------------------------------------------------- \n");
}