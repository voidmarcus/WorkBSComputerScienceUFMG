#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "sbb.h"
#include "binaryTree.h"

#define SBB_VERTICAL 0
#define SBB_HORIZONTAL 1
#define TRUE 1
#define FALSE 0


ArvoreSBB* criaArvoreSBB(Elemento* r){
	ArvoreSBB *no = malloc(sizeof(ArvoreSBB));
	no->reg = r;
	no->esq = NULL;
	no->dir = NULL;
	no->esqtipo = SBB_VERTICAL;
	no->dirtipo = SBB_VERTICAL;
	return no;
}

Elemento* pesquisaSBB(ArvoreSBB *t, Chave x){
	if (t == NULL) {
			printf("Registro não esta presente na árvore\n");
		}

		else if (x < t->reg->matricula)
			pesquisaSBB(t->esq, x); /* busca no filho esquerdo */
		else if (x > t->reg->matricula)
			pesquisaSBB(t->dir, x); /* busca no filho direito */
		else
			return t->reg;

		return t->reg; //cuidad com isso
}


void ee(ArvoreSBB** ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *esq = no->esq;

	no->esq = esq->dir; // rotD(ptr)
	esq->dir = no;

	esq->esqtipo = SBB_VERTICAL;
	no->esqtipo = SBB_VERTICAL;

	*ptr = esq;
}

void dd(ArvoreSBB** ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *dir = no->dir;

	no->dir = dir->esq; // rotE(ptr)
	dir->esq = no;

	dir->dirtipo = SBB_VERTICAL;
	no->dirtipo = SBB_VERTICAL;

	*ptr = dir;
}

void ed(ArvoreSBB** ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *esq = no->esq;
	ArvoreSBB *dir = esq->dir;

	esq->dir = dir->esq; // rotE(&(no->esq))
	dir->esq = esq;

	no->esq = dir->dir; // rotD(ptr)
	dir->dir = no;

	esq->dirtipo = SBB_VERTICAL;
	no->esqtipo = SBB_VERTICAL;

	*ptr = dir;
}

void de(ArvoreSBB** ptr){
	ArvoreSBB *no = *ptr;
	ArvoreSBB *dir = no->dir;
	ArvoreSBB *esq = dir->esq;

	dir->esq = esq->dir; // rotD(&(no->dir))
	esq->dir = dir;

	no->dir = esq->esq; // rotE(ptr)
	esq->esq = no;

	dir->esqtipo = SBB_VERTICAL;
	no->dirtipo = SBB_VERTICAL;

	*ptr = esq;
}

void iInsere(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim){
	/* adiciona, pois encontrou uma folha */
	if(*ptr == NULL)
		iInsereAqui(r, ptr, incli, fim);

	/* busca na sub-árvore esquerda */
	else if (r->matricula < (*ptr)->reg->matricula) {
		iInsere(r, &(*ptr)->esq, &(*ptr)->esqtipo, fim);
		if (*fim) return;
		if ((*ptr)->esqtipo == SBB_VERTICAL) {
			*fim = TRUE;
		}
		else if ((*ptr)->esq->esqtipo == SBB_HORIZONTAL) {
			ee(ptr); *incli = SBB_HORIZONTAL;
		}
		else if ((*ptr)->esq->dirtipo == SBB_HORIZONTAL) {
			ed(ptr); *incli = SBB_HORIZONTAL;
		}
	}

	/* busca na sub-árvore direita */
	else if (r->matricula > (*ptr)->reg->matricula){
		iInsere (r, &(*ptr)->dir, &(*ptr)->dirtipo, fim);
		if (*fim) return;
		if ((*ptr)->dirtipo == SBB_VERTICAL){
			*fim = TRUE;
		}
		else if ((*ptr)->dir->dirtipo == SBB_HORIZONTAL){
			dd(ptr); *incli = SBB_HORIZONTAL;
		}
		else if ((*ptr)->dir->esqtipo == SBB_HORIZONTAL){
			de(ptr); *incli = SBB_HORIZONTAL;
		}
	/* chave já existe */
	}

	else{
		printf("erro: chave já está na árvore.\n");
		*fim = TRUE;
	}
}

void iInsereAqui(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim){
	ArvoreSBB *no = malloc(sizeof(ArvoreSBB));
	no->reg = r;
	no->esq = NULL;
	no->dir = NULL;
	no->esqtipo = SBB_VERTICAL;
	no->dirtipo = SBB_VERTICAL;
	*ptr = no;
	*incli = SBB_HORIZONTAL;
	*fim = FALSE;
}


void insereElementoSBB(ArvoreSBB** t, Elemento *n){
	int fim = FALSE;
	int inclinacao = SBB_VERTICAL;
	iInsere(n, t, &inclinacao, &fim);
}

void inicializa(ArvoreSBB** raiz){
	*raiz = NULL;
}

void imprimeArvoreSBB(ArvoreSBB* t){
	if (t!= NULL) {
		//imprimeArvore(arvore);
	    imprimeArvoreSBB(t->esq);

		imprimeAluno(t->reg);
		//printf("%d\n", t->reg->matricula);

	    imprimeArvoreSBB(t->dir);
	}
}

void apagaArvoreSBB(ArvoreSBB *t){
	if (t != NULL){
		apagaArvoreSBB(t->dir);
		apagaArvoreSBB(t->esq);
		free(t);
	}
}
