#include <stdio.h>

void troca (int *ptr_a, int *ptr_b){
	int aux = 0;

	aux = *ptr_b;
	*ptr_b = *ptr_a;
	*ptr_a = aux;

	printf ("a: %d\n", *ptr_a);
	printf ("b: %d\n", *ptr_b); 
}


int main (){

	int a, b;

	scanf ("%d", &a);
	scanf ("%d", &b);

	troca (&a, &b);

	return 0;
}