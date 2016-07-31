#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "binaryTree.h"
#include "sbb.h"
#include "hash.h"

int funcaoHash(Elemento *ele, Hash *h){
	return (ele->matricula % h->tam);
}

//inicializa com tamanho passado (aloca)
Hash* criaHash(int t, int boolSBB){
	int i;

	Hash *h =malloc(sizeof(Hash));
	h->tam=t;
	h->nElem=0;

	if (boolSBB==1){
		h->hashSBB = (ArvoreSBB**) malloc(t*sizeof(ArvoreSBB*));

		for(i=0;i<t;i++){
			h->hashSBB[i]=NULL;
		}
	} else{
		h->hash = (Arvore**) malloc(t*sizeof(Arvore*));

		for(i=0;i<t;i++){
			h->hash[i]=NULL;
		}
	}
	return h;
}


//desaloca Hash h
void apagaHash(Hash* h,int boolSBB){
	int i=0;
	if(boolSBB==0){
		for(i=0; i<h->tam;i++){
			apagaArvore(h->hash[i]);
		}
		free(h->hash);
	}else{
			for(i=0; i<h->tam;i++){
				apagaArvoreSBB(h->hashSBB[i]);
			}
			free(h->hashSBB);
		}
	free(h);
}


//insere um Elemento na Hash
void insereNaHash(Hash* h, Elemento* x, int boolSBB){

	int pos = funcaoHash(x, h);

	if (boolSBB==1){
		if (h->hashSBB[pos]==NULL){
				h->hashSBB[pos] = criaArvoreSBB(x);
		} else{
			insereElementoSBB(&(h->hashSBB[pos]), x);
		}
		h->nElem++;
	}else{
		if (h->hash[pos]==NULL){
			h->hash[pos] = criaArvore(x);
		} else{
			insereElemento(h->hash[pos], x);
		}
		h->nElem++;
	}
}


//obtem um Elemento da Hash dada sua chave
Elemento * obtemDaHash(Hash* h, Chave c,int boolSBB ){
	int pos = funcaoHash(c, h);
	Elemento *x;

	if (boolSBB==1){
		x = pesquisaSBB(h->hashSBB, &c);
	} else{
		x = pesquisa(h->hash, &c);
	}
	return x;
}


//imprime a tabela Hash h
void imprime(Hash* h, int boolSBB){
	int i = 0;
	if (boolSBB == 1){
		for(i=0; i<h->tam;i++){
			if (h->hashSBB[i]!=NULL){
				printf("%d:\n",i);
				imprimeArvoreSBB(h->hashSBB[i]);
			}
		}
	} else{
		for(i=0; i<h->tam;i++){
			if (h->hash[i]!=NULL){
				printf("%d:\n",i);
				imprimeArvore(h->hash[i]);
			}
		}
	}
}

//retorna o número de elementos inseridos até o momento
int obtemNumElem(Hash* h){
	return h->nElem;
}
