#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

trieNode *CriaNode(char chave, int data) {

	trieNode *novoNode;
	novoNode = (trieNode*) calloc(1, sizeof(trieNode));

	novoNode->chave = chave;
	novoNode->valor = data;
	novoNode->prox = NULL;
	novoNode->prox = NULL;
	novoNode->filho = NULL;
	novoNode->pai = NULL;

	return novoNode;
}

trieNode* ProcuraTrie(trieNode *raiz, const char *chave) {
	trieNode *level = raiz->filho;

	while (1) {
		trieNode *encontrado = NULL;
		trieNode *atual;

		int lvl = 0;

		//Encontra a chave no level
		for (atual = level; atual != NULL; atual = atual->prox) {
			if (atual->chave == *chave) {
				encontrado = atual;
				lvl++;
				break;
			}
		}

		if (encontrado == NULL) {
			return NULL;
		}

		if (*chave == '\0') {
			return atual;
		}

		level = encontrado->filho;
		chave++;
	}
}

void ComputaTexto(trieNode *raiz, const char *chave) {
	trieNode *level = raiz->filho;

	while (1) {
		trieNode *encontrado = NULL;
		trieNode *atual;

		for (atual = level; atual != NULL; atual = atual->prox) {
			if (atual->chave == *chave) {
				encontrado = atual;
				break;
			}
		}

		if (encontrado == NULL) {
			return;
		}

		if (*chave == '\0') {
			atual->valor++;
		}

		level = encontrado->filho;
		chave++;
	}
}

int ProcuraValor(trieNode *raiz, const char *chave) {
	trieNode *level = raiz->filho;

	while (1) {
		trieNode *encontrado = NULL;
		trieNode *atual;

		for (atual = level; atual != NULL; atual = atual->prox) {
			if (atual->chave == *chave) {
				encontrado = atual;
				break;
			}
		}

		if (encontrado == NULL) {
			return 0;
		}

		if (*chave == '\0') {
			return atual->valor;
		}

		level = encontrado->filho;
		chave++;
	}
}

void AddTrie(trieNode **raiz, char *chave, int data) {
	trieNode *ponteiro = NULL;

	if (NULL == *raiz) {
		printf("Erro: raiz nula");
		return;
	}

	ponteiro = (*raiz)->filho;

	//Insere o primeiro elemento
	if (ponteiro == NULL) {
		for (ponteiro = *raiz; *chave; ponteiro = ponteiro->filho) {
			ponteiro->filho = CriaNode(*chave, 0xffffffff);
			ponteiro->filho->pai = ponteiro;
			chave++;
		}
		ponteiro->filho = CriaNode('\0', data);
		ponteiro->filho->pai = ponteiro;
		return;
	}

	if (ProcuraTrie(ponteiro, chave)) {
		return;
	}

	//Desce de nivel enquanto a chave seja igual
	while (*chave != '\0') {
		if (*chave == ponteiro->chave) {
			chave++;
			ponteiro = ponteiro->filho;
		} else {
			break;
		}
	}

	//Muda para o vizinho de mesmo nivel, caso a chave seja diferente
	while (ponteiro->prox) {
		if (*chave == ponteiro->prox->chave) {
			chave++;
			AddTrie(&(ponteiro->prox), chave, data);
			return;
		}
		ponteiro = ponteiro->prox;
	}

	//Caso os niveis anteriores sejam prefixos e ainda tenha sufixo...
	if (*chave) {
		ponteiro->prox = CriaNode(*chave, 0xffffffff);
	} else {
		ponteiro->prox = CriaNode(*chave, data);

	}

	ponteiro->prox->pai = ponteiro->pai;
	ponteiro->prox->ante = ponteiro;

	if (!(*chave)) {
		return;
	}

	chave++;

	for (ponteiro = ponteiro->prox; *chave; ponteiro = ponteiro->filho) {
		ponteiro->filho = CriaNode(*chave, 0xffffffff);
		ponteiro->filho->pai = ponteiro;
		chave++;
	}

	ponteiro->filho = CriaNode('\0', data);
	ponteiro->filho->pai = ponteiro;

	return;

}

void CriaTrie(trieNode **raiz) {
	*raiz = CriaNode('\0', 0xffffffff);
}

void ImprimiTrie(trieNode *raiz, int lvl) {

	trieNode *level = raiz;
	trieNode *atual;

	//Percorre os vizinhos (prox)
	for (atual = level; atual != NULL; atual = atual->prox) {
		printf("\n\nlvl=%d - Atual=%c", lvl, atual->chave);

		if (atual->chave == '\0') {
			printf(" Valor =%d", atual->valor);
		}

		//Percorre todos os leveis (filhos)
		if (atual->filho != NULL) {
			ImprimiTrie(atual->filho, lvl + 1);
		}

	}
}

void DesalocaTrie(trieNode* raiz) {
	trieNode *ponteiro = raiz;
	trieNode *temp = raiz;

	while (ponteiro != NULL) {
		while (ponteiro->filho != NULL) {
			ponteiro = ponteiro->filho;
		}
		if (ponteiro->ante && ponteiro->prox) {
			temp = ponteiro;
			ponteiro->prox->ante = ponteiro->ante;
			ponteiro->ante->prox = ponteiro->prox;
			free(temp);
		} else if (ponteiro->ante && !(ponteiro->prox)) {
			temp = ponteiro;
			ponteiro->ante->prox = NULL;
			free(temp);
		} else if (!(ponteiro->ante) && ponteiro->prox) {
			temp = ponteiro;
			ponteiro->pai->filho = ponteiro->prox;
			ponteiro->prox->ante = NULL;
			ponteiro = ponteiro->prox;
			free(temp);
		} else {
			temp = ponteiro;
			if (ponteiro->pai == NULL) {
				free(temp);
				return;
			}
			ponteiro = ponteiro->pai;
			ponteiro->filho = NULL;
			free(temp);
		}
	}

}
