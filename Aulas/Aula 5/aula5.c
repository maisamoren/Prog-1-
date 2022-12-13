// Exercicio da Aula 5
// GRR20204081 - Maisa Girardi

# include <stdio.h>

int main (){
	int temperatura = 25;
	int i;

	for (i = temperatura; i <= 92; i++){
		if ((i >= 30) && (i <= 40)){
			printf ("Placa de vídeo ociosa \n");
		}
		if ((i > 60) && (i < 85)){
			printf ("Placa sob carga \n");
		} 
		if ((i >= 83) && (i < 92)){
			printf ("Controle térmico em curso, limitando processamento \n");
		}
		if (i >= 92) {
			printf ("Temperatura crítica, desligando...\n");
		}
	}
	return 0;
}