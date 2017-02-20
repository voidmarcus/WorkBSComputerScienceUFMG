/*
 ============================================================================
 Name        : Numeros_Ahmoc.c
 Author      : Marcus Vinicius de Oliveira
 Version     : 1.1
 Copyright   : AEDs 3 - PA 1.2
 Description : Números de Ahmoc - URI Online Judge | 2049 - PA1.2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_a 1000010
#define MAX_p 300010
// MAX char table (ASCII)
#define MAX 1000010

// Boyer-Moore-Horspool-Sunday algorithm for string matching
int bmhs(char *string, int n, char *substr, int m) {
	int d[MAX];
	int i, j, k;

	// pre-processing
	for (j = 0; j < MAX; j++)
		d[j] = m + 1;
	for (j = 0; j < m; j++)
		d[(int) substr[j]] = m - j;

	// searching
	i = m - 1;
	while (i < n) {
		k = i;
		j = m - 1;
		while ((j >= 0) && (string[k] == substr[j])) {
			j--;
			k--;
		}
		if (j < 0)
			return k + 1;
		i = i + d[(int) string[i + 1]];
	}

	return -1;
}

int main(void) {
	char a[MAX_a];
	int h = 1;
	char painel[MAX_p];

	while (a != '0') {

		scanf("%s", &a);
		if (atoi(a) == 0) {
			break;
		}

		if (h != 1) {
			printf("\n");
		}
		printf("Instancia %d\n", h);
		scanf("%s", &painel);

		//verifica se existe substring na string
		if (bmhs(painel, strlen(painel), a, strlen(a)) != -1) {
			printf("verdadeira\n");
		} else {
			printf("falsa\n");
		}

		h++;
	}

	return EXIT_SUCCESS;
}
