#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "backend.h"
#include <sys/time.h>

int main(int argc, char const *argv[]) {

	// Criações e atribuições de variaveis
  if (argc){

  }

  int qt_threads = atoi(argv[1]);

	int n, m;
	int i, j;
	data dados[qt_threads]; //Cria qt_threads de tipo data
  data *pt;
  pt = &dados[0];

  scanf("%d %d", &m, &n);
	//m linhas // n colunas

  alocaData (pt, m, n, qt_threads);

	//leitura da matriz e armazenamento em memoria principal
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &dados[0].grid[i][j]);

  // Seta dados[1 a qt_threads] para dados em memoria
  for (i = 1; i < atoi(argv[1]); i++) {
    dados[i].grid = dados[0].grid;
    dados[i].m = dados[0].m;
    dados[i].n = dados[0].n;
    dados[i].qt_threads = dados[0].qt_threads;
    dados[i].vetor = dados[0].vetor;
  }

  // Inicio da medida de tempo
  struct timeval start, end;
  gettimeofday(&start, NULL);

	// Criação e chamada das threads
	pthread_t threads[qt_threads];
	for (i = 0; i < qt_threads; i++) {
    dados[i].thread_id = i;
		pthread_create(&threads[i], NULL, calcMax, (void*) &dados[i]);
	}

  // Sincronismo de threads
	for (i = 0; i < qt_threads; i++) {
		pthread_join(threads[i], NULL);
	}

  // Calcula a soma maxima do vetor final
  calVetFinal (&(dados[0].vetor[0]), m);

  // Fim da medição
  // Tecnica ninja encontrada em : http://stackoverflow.com/questions/12722904/how-to-use-struct-timeval-to-get-the-execution-time
  gettimeofday(&end, NULL);
  int tmili;
  tmili = (int) (1000 * (end.tv_sec - start.tv_sec)
      + (end.tv_usec - start.tv_usec) / 1000);
  printf("Time %d ms\n", tmili);

  //Imprime resultado
	printf("resultado = %d\n", dados[0].vetor[0]);

  desAlocaData (pt, m);

	return 0;
}
