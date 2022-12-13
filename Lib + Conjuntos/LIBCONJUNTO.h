#ifndef __LIBCONJUNTO__
#define __LIBCONJUNTO__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Entrada ();
int Ler ();
void Tamanho (int *tam);
void VetorVazio (int *t);
void ImprimeVetor (int *vetor, int tam);
void InsertOrder (int *vetor, int tam);
void ElemAleatorio (int *vetor);
void Uniao (int tam);
void Intersec (int tam);
void Saida (); 

#endif 