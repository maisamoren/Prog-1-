// LIBCONJUNTO.H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprime (){ //---------------------------------------------------------------------------------
	printf ("BEM VINDO XD ");
	printf ("\n");

	printf ("MENU: \n");
	printf ("\n ! OBSERVAÇÃO: o conjunto deve ser de elementos inteiros positivos ! \n");
 	printf ("\n");

	printf ("Digite 1 para verificar se um conjunto eh vazio. \n");
	printf ("Digite 2 para devolver o tamanho de um conjunto. \n");
	printf ("Digite 3 para preencher um conjunto. \n");
	printf ("Digite 4 para criar um conjunto de elementos aleatorios. \n");
	printf ("Digite 5 para ver um conjunto UNIAO de dois outros conjuntos. \n");
	printf ("Digite 6 para ver um conjunto INTERSECCAO de dois outros conjuntos. \n");
	printf ("Digite 0 para sair do programa. \n");
}


int Ler (){ //-------------------------------------------------------------------------------------
	int m;
	
	scanf ("%d", &m);
	return m;
}


// problema com imprimir !!!!!!!!!!!!
int ImprimeVetor (int *vetor, int tam){ //---------------------------------------------------------------------------
	int cha;

	printf ("\n");
	printf ("Para imprimir o vetor, digite 1. Caso contrário, digite 0. \n");
	scanf ("%d\n", &cha);

	if (cha == 1){
		for (int j = 0; j < tam; j++){
    		printf ("%d ", vetor[j]);
		}
	}
	else
		return 0;
	return 0;
}


// ARRUMAR
void VetorVazio (int *v, int tam){ //------------------------------------------------------------------------
	if (*v == -1) {
		printf ("O vetor é vazio. \n");

	printf ("O vetor não é vazio. \n");
	}
}


int Tamanho (int tam){ //--------------------------------------------------------------------------
	
	printf ("Digite um tamanho para um conjunto: \n");
	tam = Ler();

	printf ("\n");
	printf ("O tamanho do conjunto é: %d\n", tam);
	return 0;
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
	// imprimevetor
}


int ElemAleatorio (int tam){ //-------------------------------------------------------------------
	int aux, j;
	int vetor [tam];
	srand((unsigned)time(NULL));
	for (int i = 0; i < tam ; i++) {
		vetor[i] = rand() % 101;
		aux = vetor[i];
		j = i - 1;
		while ((j>= 0) && (vetor[j] > aux)){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
	return vetor;
	// imprimevetor
}


void Uniao (int tam){ //-----------------------------------------------------------------------------------
	int dobro, a;
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
	a = (dobro + tam) / 2;
	for (int n = 0; n < a ; n++){
    	printf ("%d ", c3[n]);
	}
	printf ("\n");
}


void Intersec (int tam) { //------------------------------------------------------------------------
	int c1[tam], c2[tam], c3[tam];
	int i = 0, j = 0, k = 0; 
	int b, aux, n;

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