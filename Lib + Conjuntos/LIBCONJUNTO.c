// LIBCONJUNTO
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LIBCONJUNTO.h"
#define MAX 100

void Entrada (){ //---------------------------------------------------------------------------------
	printf ("BEM VINDO XD ");
	printf ("\n");

	printf ("MENU: \n");
	printf ("\n ! OBSERVAÇÃO: o conjunto deve ser de elementos inteiros positivos ! \n");
 	printf ("\n");

	printf ("1 - Verifica se um conjunto eh vazio. \n");
	printf ("2 - Retorna o tamanho de um conjunto. \n");
	printf ("3 - Preenche um conjunto. \n");
	printf ("4 - Cria um conjunto de elementos aleatorios. \n");
	printf ("5 - Retorna um conjunto UNIAO de dois outros conjuntos. \n");
	printf ("6 - Retorna um conjunto INTERSECCAO de dois outros conjuntos. \n");
	printf ("0 - Saída o programa. \n");
	printf ("\n");
	printf ("Digite algum índice do menu: \n");
	printf ("(de 0 à 6) \n");
}


int Ler (){ //-------------------------------------------------------------------------------------
	int m;
	
	scanf ("%d", &m);
	return m;
}


void Tamanho (int *tam){ //--------------------------------------------------------------------------
	
	printf ("Digite um tamanho para um conjunto: ");
	*tam = Ler();
	printf ("\n");
}


void VetorVazio (int *t){ //------------------------------------------------------------------------
	if (*t == 0) {
		printf ("O vetor é vazio. \n");
	}
	else {
		printf ("O vetor não é vazio. \n");
	}
}


void ImprimeVetor (int *vetor, int tam){ //---------------------------------------------------------------------------

	for (int j = 0; j < tam; j++){
    	printf ("%d ", vetor[j]);
	}
	printf ("\n");
}


void InsertOrder (int *vetor, int tam){ //----------------------------------------------------------
	int aux, j;

	printf ("Digite um vetor de tamanho %d: \n", tam);
	for (int i = 0; i < tam; i++) {
		scanf ("%d", &vetor[i]);
		aux = vetor[i];
		j = i - 1;
		while ((j>= 0) && (vetor[j] > aux)){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
	 ImprimeVetor (vetor, tam);
}


void ElemAleatorio (int *vetor){ //-------------------------------------------------------------------
	int aux, j;
	// printf ("aqui\n");

	srand((unsigned)time(NULL));
	// printf("%d\n", tam);

	for (int i = 0; i < MAX ; i++) {
		vetor[i] = rand() % 101;
		aux = vetor[i];
		j = i - 1;
		while ((j>= 0) && (vetor[j] > aux)){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}

	ImprimeVetor (vetor, j);
}


void Uniao (int tam){ //-----------------------------------------------------------------------------------
	int dobro;
	dobro = tam * 2;
	int c1[tam], c2[tam], c3[dobro];
	int i = 0, j = 0, k = -1; 

// os conjuntos c1 e c2 serao dados pelo usuário 
	InsertOrder (c1, tam);
	InsertOrder (c2, tam);

// calculo da uniao
	while ((i < tam) && (j < tam)){
		k++;
		if (c1[i] < c2[j]){
			c3[k] = c1[i];
			i++;
		}
		else if (c1[i] > c2[j]){
				c3[k] = c2[j];
				j++;
		}
		else {
			c3[k] = c1[i];
			i++;
			j++;
		}
	}

	if (i < tam){
		for (int l = i; l < dobro; l++){
			k++;
			c3[k] = c1[l];
		}
	}

	else if (j < tam){
		for (int l = j; l < dobro; l++){
			k++;
			c3[k] = c2[l];
		}
	}

	printf ("\n");
	printf ("O conjunto UNIAO do conjunto 1 e 2 é: \n");
	for (int n = 0; n < dobro ; n++){
		if (c3[n] != 0){
    		printf ("%d ", c3[n]);
    	}
	}
	printf ("\n");
}


void Intersec (int tam) { //------------------------------------------------------------------------
	int c1[tam], c2[tam], c3[tam];
	int i = 0, j = 0, k = 0; 

// os conjuntos c1 e c2 serao dados pelo usuário 
	InsertOrder (c1, tam);
	InsertOrder (c2, tam);

//  calculo da interseccao
	while ((i < tam) && (j < tam)){
		if (c1[i] < c2[j])
			i++;
		else {
			if (c1[i] > c2[j])
				j++;
			else { // O ELEMENTO ESTEJA NOS DOIS CONJUNTOS
				c3[k] = c1[i];
				k++;
				i++;
				j++;
			}
		}
	}

// imprimir os vetores
	printf ("\n");
	printf ("O conjunto 1 é: \n");
	for (int n = 0; n < tam; n++){
    	printf ("%d ", c1[n]);
  	}

  	printf ("\n");
  	printf ("O conjunto 2 é: \n");
  	for (int n = 0; n < tam; n++){
    	printf ("%d ", c2[n]);
  	}

  	printf ("\n");
	printf ("O conjunto INTERSECCAO do conjunto 1 e 2 é: \n");
	for (int n = 0; n < k; n++){
    	printf ("%d ", c3[n]);
	}
}


void Saida (){
	printf ("\n");
	printf ("Obrigada por usar o programa  =) \n");
	printf ("\n");
	printf ("Tchau! \n");
}