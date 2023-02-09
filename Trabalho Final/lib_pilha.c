#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

// struct nó
struct item{
    char ingr;
    struct item *prox;
}

// struct pilha
struct pilha {
    struct item *topo;
}

// FUNCOES DA PILHA 
struct pilha *incializaPilha (){
    struct pilha *burger;
    burger = malloc(sizeof(struct pilha));
    burger->topo = VAZIO;
    return burger;
}

int pilhaVazia (struct pilha *burger){
    if (burger->topo != VAZIO)
        return 0;
    return 1;
}

struct item *cria_item(char ingr){
    struct item *
}

____ push (){
}

____ pop (){
}

____ fazer_pedido () {
// primeiro verificar qtos elementos ele empilha 
    int comp = 7; // comprimento da pilha 

    struct pilha *burger = incializaPilha(); // topo

    int tam = 0; // tamanho da pilha

// inserir novo elemento na pilha 
    pilha *burger = cria_item();
    
    // verifica se tem espaço
        // tam < comp
        // overflow:
        pilhaVazia()
    
    // insere na pilha
        // push (pilha p, elemento x)
        push ();

    // atualiza o topo
        // topo aponta pra novo elemento

// remover um elemento da pilha
    // obtem o elemento do topo

    // atualiza o topo
        // topo aponta pra elemento anterior

    //libera a memoria
        // pop (pilha p)
        pop ();
        // underflow:
            // se topo = vazio 
                // pilha está vazia

}

/* ---------------------------------------------------------- */
// ADICIONAR NO MAKEFILE:

        //lib_pilha.o: lib_pilha.c lib_pilha.h
	        //gcc $(CFLAGS) -c lib_pilha.c -lncurses -ltinfo