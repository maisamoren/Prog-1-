// TESTE	
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int Ler (){ //-------------------------------------------------------------------------------------
	int m;
	
	scanf ("%d", &m);
	return m;
}

int Tamanho (int tam){ //--------------------------------------------------------------------------
	
	printf ("Digite um tamanho para um conjunto: \n");
	tam = Ler();

	printf ("\n");
	printf ("O tamanho do conjunto é: %d\n", tam);
	return 0;
}

void VetorVazio (int *v, int tam){ //------------------------------------------------------------------------
	if (*v == -1) {
		printf ("O vetor é vazio. \n");

	printf ("O vetor não é vazio. \n");
	}
}


// MAIN PROGRAM 

int main (){
	int tam = 0;
	int conj[MAX];
	// int menu, tam;

	// Imprime ();
	
	// menu = Ler ();

	Tamanho (tam);

	VetorVazio (conj, tam);
	
	return 0;
}