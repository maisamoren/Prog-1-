#include <stdio.h>


int main (){

// resolução da letra a
	int m = 10;
	int *ptr_m = &m;
	printf("o endereço de m é: %p\n", ptr_m);
	printf ("\n");

// resolução da letra b
	//?
	// printf ("\n");

// resolução da letra c
	printf("o valor armazenado em z é: %d\n", *z);
	printf ("\n");

// resolução da letra d
	int n;
	int ptr_n = &n;
	printf("o endereço de n é: %p\n", ptr_n);
	printf ("\n");

// resolução da letra e
	int o, ptr_o;
	ptr_n = ptr_o;
	printf("o novo endereço de n é: %p\n", ptr_n);
	printf ("\n");
	
// resolução da letra f
	o = m;
	printf("o valor de o é: %d\n", o);
	printf ("\n");

// resolução da letra g
	// ?
	// printf ("\n");

	return 0;
}