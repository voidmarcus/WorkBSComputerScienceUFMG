
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "backend.h"

int max(int a, int b) {
	if (a < b)
		return b;
	return a;
}

void *calcMax(void *pt) {
	int i, j, qt_threads;
	int k, m;
	data *dados;
	dados = (data*)pt;

	qt_threads = dados->qt_threads;

	for (i = 0; i < dados->m; i++) {
		// if --> Divide a matriz grid em vetores para as threads.
		if (i % qt_threads == dados->thread_id) {
      // Encontra a soma maxima dos elementos de um vetor e
      // o armazena na posição [0] do mesmo.
			for (j = (int) dados->n - 2; j >= 0; j--) {
				dados->grid[i][j] = max(
						dados->grid[i][j + 2] + dados->grid[i][j],
						dados->grid[i][j + 1]);
			}
			dados->vetor[i] = dados->grid[i][0];
		}
	}
}

void calVetFinal (int *vetor, int m){
  int j;

  for (j = m - 2; j >= 0; j--) {
    vetor[j] = max((int)vetor[j + 2] + (int)vetor[j], vetor[j + 1]);
  }

}

void alocaData (data *dados, int m, int n, int qt_threads){
  int i;

  dados->m = (int *)calloc(1, sizeof(int));
  dados->n = (int *)calloc(1, sizeof(int));

  dados->qt_threads = (int *)calloc(1, sizeof(int));

  // +2, por inerência da função calcmax
  dados->grid = (int**) calloc(m + 1, sizeof(int*));
  for (i = 0; i < m; i++)
    dados->grid[i] = (int*) calloc((int *)n + 2, sizeof(int));

  dados->vetor = (int*) calloc(dados->n + 2, sizeof(int));

  dados->qt_threads = qt_threads;
  dados->m = m;
  dados->n = n;
}

void desAlocaData (data *dados, int m){
  int i;

  //free (dados->m);
  //free (dados->n);

  //free (dados->qt_threads);

  for (i = 0; i < m; i++)
    free (dados->grid[i]);
  free (dados->grid);

  free (dados->vetor);
}
