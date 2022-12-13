// MAIN PROGRAM 
#include <stdio.h>
#include "LIBCONJUNTO.h"
#define MAX 100

int main (){
	int menu, tam;
	int *ptr = &tam;
	int conj[MAX];

	Entrada ();
	menu = Ler ();

	if (menu == 1){
		Tamanho (ptr);
		if (tam != 0){
			InsertOrder (conj, tam);
		} 
		VetorVazio (ptr);
	}

	else if (menu == 2){
		Tamanho (ptr);
		printf ("O tamanho do conjunto é: %d\n", tam);
		printf ("\n");
	}

	else if (menu == 3){
		Tamanho (ptr);
		if (tam != 0){
			InsertOrder (conj, tam);
		} 
	}

	else if (menu == 4){
		ElemAleatorio (conj);
	}

	else if (menu == 5){
		Tamanho (ptr);
		Uniao (tam);
	}

	else if (menu == 6){
		Tamanho (ptr);
		Intersec (tam);
	}

	Saida ();

	return 0;

}