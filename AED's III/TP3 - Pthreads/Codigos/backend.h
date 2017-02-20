#ifndef BACK
#define BACK

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct data {
	int *vetor;
	int **grid;
  int *qt_threads;
	int *m;
	int *n;
	int thread_id;
} data;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Função: Dado dois inteiros, retorna o maior
*Entrada: Dois inteiros A e B
*Saída: Maior inteiro entre A e B
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int max(int a, int b);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Função: Divide grid em vetores para as threads e encontra a soma
*maxima dos elementos de um vetor, dada restrição do pd
*Entrada: Tipo abstrato (redefinido para tipo data dentro da função)
*Saída: Nenhuma | void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void *calcMax(void *pt);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Função: Encontra a soma maxima dos elementos de um vetor, dada restrição do pd
*Entrada: Ponteiro para vetor e inteiro m (numero de elementos do vetor)
*Saída: Nenhuma | void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void calVetFinal (int *vetor, int m);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Função: Aloca estruturas necessárias para o TAD data
*Entrada: Endereço de instancia data, numeri de linhas, num de colunas, qt de
*threads
*Saída: Nenhuma | void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void alocaData (data *dados, int m, int n, int qt_threads);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Função: Desaloca estrutura data
*Saída: Nenhuma | void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void desAlocaData (data *dados, int m);

#endif
