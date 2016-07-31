#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "aluno.h"

Arvore* criaArvore(Elemento* r){
	Arvore *novo;
	novo = malloc(sizeof(Arvore));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->reg = r;

	return novo;
}

Elemento* pesquisa(Arvore *t, Chave x){
	if (t == NULL) {
		printf("Registro não esta presente na árvore\n");
	}

	else if (x < t->reg->matricula)
		pesquisa(t->esq, x); /* busca no filho esquerdo */
	else if (x > t->reg->matricula)
		pesquisa(t->dir, x); /* busca no filho direito */
	else
		return t->reg;

	return t->reg; //cuidad com isso
}

void insereElemento(Arvore* t, Elemento *n){
	if(n->matricula < t->reg->matricula) { 								/* chave menor */
		if (t->esq){
			insereElemento(t->esq, n);
		}
		else { 													/* achou local de inserção */
			Arvore *novo = criaArvore(n);
			t->esq = novo;
		}
	}

	else {														 /* chave maior ou igual ao nodo atual */
		if (t->dir){
			insereElemento(t->dir, n);
		}
		else {
			Arvore *novo = criaArvore(n);
				t->dir = novo;
		}
	}
}

Arvore* removeDaArvore(Arvore* t, Chave c){
	Arvore *aux;

	if(t == NULL) {printf("Elemento Ausente\n");}
	else if(c < t->reg->matricula){ t->esq=removeDaArvore(t->esq, c); }
	else if(c > t->reg->matricula){ t->dir=removeDaArvore(t->dir, c); }
	else if (t->esq == NULL && t->dir == NULL) {
		free(t); return NULL; /* zero filhos */
	}
	else if(t->esq == NULL) {
		aux = t->dir; free(t); return aux; /* 1 filho direita */
	}
	else if(t->dir == NULL) {
		aux = t->esq; free(t); return aux; /* 1 filho esquerda */
	} else { /* 2 filhos */
		Arvore *suc = achaMenor(t->dir);
		t->reg = suc->reg;
		t->dir = removeDaArvore(t->dir, suc->reg->matricula);
		return t;
	}
	return t;
}

Arvore* achaMenor(Arvore* t){
	if(t->esq == NULL) {
		return t;
	}

	return achaMenor(t->esq);
}

void imprimeArvore(Arvore *t){
	  if (t!= NULL) {
		  imprimeArvore(t->esq);
		  imprimeAluno(t->reg);
		  //printf("%d\n", t->reg->matricula);;
		  imprimeArvore(t->dir);
	  }
}

void apagaArvore(Arvore *t){
	if (t != NULL){
		apagaArvore(t->dir);
		apagaArvore(t->esq);
		free(t);
	}
}
