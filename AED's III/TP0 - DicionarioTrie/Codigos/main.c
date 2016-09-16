#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

int main(int argc, char const *argv[]) {
	int n, i, m;

	trieNode *raiz;
	CriaTrie(&raiz);

	scanf("%d", &n);

	//Leitura e construcao do dicionario
	char dicionario[n][16];
	for (i = 0; i < n; i++) {
		scanf("%s", dicionario[i]);
		AddTrie(&raiz, dicionario[i], 0);
	}

	//Leitura e computacao do texto
	scanf("%d", &m);
	char tex[50];
	for (i = 0; i < m; i++) {
		scanf("\n%s", &tex);
		ComputaTexto(raiz, tex);
	}

	//Imprensao dos valores atraves da busca na arvore
	for (i = 0; i < n; i++) {
		printf (" %d ",ProcuraValor(raiz, dicionario[i]));
	}
	printf("\n");

	DesalocaTrie(raiz);

	return 0;
}
