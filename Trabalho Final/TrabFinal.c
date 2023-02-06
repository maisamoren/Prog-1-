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

int main () {
  int p; 
    p = 0;
    // para iniciar o programa/jogo
    entrada (&p);
    
    COORDENADAS chapeiro;
    colocar_chapeiro(&chapeiro);
    
  char **mapa;
    mapa = fazer_mapa ();
  
    for (int i = 0; i < LIN; i++){
      for (int j = 0; j < COL; j++)
        printf ("%c ", mapa[i][j]);
      printf ("\n");
    }

    // para sair do jogo
    saida ();

    return 0;
}