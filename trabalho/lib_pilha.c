#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

#include "lib_pilha.h"
#include "lib_inicio.h"

// FUNCOES DA PILHA 
t_pilha *incializaPilha (){

    t_pilha *burger = malloc(sizeof(t_pilha));

    if (burger == NULL){
        free(burger);
        return NULL;
    }
    else{

	    burger->topo = -1;
	
	    burger->ingr = malloc(sizeof(char)* MAX);
	if (burger == NULL)
        return NULL;
    }

    return burger;
}

t_pilha *destroi_pilha (t_pilha *burger){
    free(burger-> ingr);
    free(burger);
    return NULL;
}

int pilhaVazia (t_pilha *burger){
    return burger->topo == -1;
}

int push (t_pilha *burger, char ingrediente){

    if (burger->topo == MAX)
	    return 0;

    else {
	    burger-> topo++;
	    burger-> ingr[burger-> topo] = ingrediente;
	
    return 1;
    }
}

int pop(t_pilha *burger, char *aux){

    if (pilhaVazia(burger))
        return 0;

    else {
	    *aux = burger-> ingr[burger->topo];
	    burger-> topo--;
	    return 1;
    }

    // aux = burger->topo;
    // burger->topo = aux->anterior;

    // free(aux);
    // aux = NULL;
}

void imprime_pilha(t_pilha *burger){

    int x = 0;
    int y = 0;

    for (int i = 0; i <= burger->topo; i++) {
        mvprintw(x, y, "[%c]", burger->ingr[i]);
        y = y+3;
    }

    // int x = 0;
    // int y = 0;

    // t_item *aux = burger->topo;

    // if(burger->topo != NULL){
        
    //     if(aux->anterior == NULL){
    //         mvprintw(x, y, "[%c]", aux->ingr);
    //         y = y+3;
    //     }
    //     else {
    //         while (aux->anterior != NULL)
    //         {
    //             mvprintw(x, y, "[%c]", aux->ingr);
    //             aux = aux->anterior;
    //             y = y+3;
    //         }
    //     }
    // }
}