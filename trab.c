// MAIN PROGRAM 
#include <stdio.h>

int main (){
	int menu, tam;
	int opcao = 10;
	int *ptr_tam = &tam;
	int conj[MAX];

	Imprime ();
	menu = Ler ();

	while (menu != 0){

		if (menu == 1)
			VetorVazio (ptr_tam);

		else if (menu == 2)
			Tamanho (ptr_tam);

		else if (menu == 3)
			InsertOrder (conj, tam);

		else if (menu == 4)
			ElemAleatorio (conj, ptr_tam);

		else if (menu == 5)
			Uniao (tam);

		else if (menu == 6)
			Intersec (tam);
	}

	Saida ();
	
	return 0;
} 