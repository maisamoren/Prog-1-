// Exercicio Aula 6
// GRR20204081 - Maisa Girardi

#include <stdio.h>
#define fil 13
#define pol 4


// preencher os assentos
void PreencherAssento (char onibus[fil][pol]){
	char x = '0';

 	for (int i = 0; i < fil; i++){
		for (int j = 0; j < pol; j++){
			if ((i == 0) && (j == 0)){
					onibus[i][j] = ' ';
			}
			else {
				if ((i == 12) && ((j == 1) || (j == 2) || (j == 3))){
					onibus[i][j] = ' ';
				}
				else {
					onibus[i][j] = x;
				}
			}
		}
	}
}


// verifica o assento do onibus
int verificarAssento(char onibus[fil][pol], int assento){
	int f, p;

	printf ("Digite o numero do assento: \n");
	scanf ("%d", &assento);

	f = assento / 4;
	p = assento % 4;

	if (onibus[f][p] == '0')
		return assento;
	else 
		return 0;
}


// reserva o assento do onibus
int reservarAssento(char onibus[fil][pol], int assento){
   int f, p;

   f = assento / 4;
	p = assento % 4;

   if (onibus[f][p] == '0'){
		onibus[f][p] = 'X';
      return 1;
	}
   else 
      return 0;
}


//imprimir o mapa do onibus
void imprimirMapa (char onibus[fil][pol]){
	int i, j;

	for (i = 0; i < fil; i++){
		for (j = 0; j < pol; j++)
			printf ("%c\t", onibus[i][j]);
		printf ("\n");
	}
}


// MAIN PROGRAM *********************************************
int main () {

	int assento, opcao, aux, reservado;
	char onibus [fil][pol];

	PreencherAssento (onibus);

	assento = 0;
   opcao = 10;
   while (opcao != 0){

      printf ("\n");
	   printf ("Digite 1 para verificar se um dado assento está ocupado ou livre \n");
	   printf ("Digite 3 para imprimir o mapa de assentos \n");
	   printf ("Digite 0 para sair do programa \n");
      scanf ("%d", &opcao);

	   if (opcao == 1){
		   aux = verificarAssento (onibus, assento);
		   if (aux > 0){
			   reservado = reservarAssento (onibus, aux);
			   printf ("%d\n", reservado);
		   }
	   }

	   if (opcao == 3)
		   imprimirMapa (onibus);

      if (opcao == 0)
	      return 0;
   }
}