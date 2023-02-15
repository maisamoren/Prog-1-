#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#include "lib_move.h"
#include "lib_pilha.h"

void entrada (){
    printw ("\n\n   DE-BURGER - O JOGO   \n\n");
}

void saida (){
    printw ("\n\nMuito obrigada por jogar!\n\nTchau =)\n\n");
}

void regra(){
    printw("\nPara jogar use as setas do teclado.\n");
    printw("    Aperte 'Q' para sair do jogo\n");

    printw("\nREGRAS DO JOGO: \n");

    printw("\nSe forem entregues 3 pedidos errados, GAME OVER.\n");
    printw("    Suas vida serão mostradas abaixo do mapa, como no exemplo:\n");
    printw("        VIDAS: 2\n");

    printw("\nSe 5 pedidos forme jogados no lixo, GAME OVER.\n");
    printw("    Exemplo: 'LIXO: X X _ _ _'.\n");

    printw ("\nPara começar o jogo, é preciso entrar com um número de pedidos.\n");
    printw ("Digite um número: ");
    
}

void menu(int vidas, int lixo, int pontos){   

    int x = 15;
    int y = 3;

    mvprintw (0, 52, "PONTOS: %d", pontos);
    mvprintw (x-2, y, "VIDAS: %d", vidas);
    mvprintw (x-2, y+15, "LIXO: %d", lixo);

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

    mvprintw(x+11, y,    " ------------------| LEGENDA |------------------ \n");
    mvprintw(x+12, y,  " |                                             | \n");
    mvprintw(x+13, y,  " |  & ->  é o cozinhero                       | \n");
    mvprintw(x+14, y,  " |  @ ->  é o ponto de entrega dos pedidos     | \n");
    mvprintw(x+15, y,  " |  o ->  é a lixeira                         | \n");
    mvprintw(x+16, y,  " |                                             | \n");
    mvprintw(x+17, y,  " |  R ->  é a estacao dos REFRIGERANTES       | \n");
    mvprintw(x+18, y,  " |  F ->  é a estacao das BATATAS FRITAS      | \n");
    mvprintw(x+19, y,  " |  p ->  é a estacao do pao (parte de BAIXO)  | \n");
    mvprintw(x+20, y,  " |  P ->  é a estacao do pao (parte de CIMA)   | \n");
    mvprintw(x+21, y, " |  Q ->  é a estacao do QUEIJO               | \n");
    mvprintw(x+22, y, " |  S ->  é a estacao da SALADA               | \n");
    mvprintw(x+23, y, " |                                             | \n");
    mvprintw(x+24, y, " ----------------------------------------------- \n");
}