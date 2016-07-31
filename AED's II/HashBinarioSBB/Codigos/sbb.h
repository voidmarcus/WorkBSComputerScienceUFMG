#ifndef SBB
#define SBB

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef Aluno Elemento;

typedef struct ArvoreSBB {
	Elemento* reg;
	struct ArvoreSBB* esq;
	struct ArvoreSBB* dir;
	int esqtipo;
	int dirtipo;
}ArvoreSBB;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:ArvoreSBB* criaArvoreSBB(Elemento* r);
*Função:Cria uma árvore com o elemento r sendo raíz.
*Entrada:Elemento r.
*Saída:Endereço contendo raiz da ArvoreSBB.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
ArvoreSBB* criaArvoreSBB(Elemento* r);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:Elemento* pesquisaSBB(ArvoreSBB *t, Chave x);
*Função:Pesquisa na árvore o elemento com chave x.
*Entrada:ArvoreSBB t e Chave x.
*Saída:Caso exista, retorna endereço da Arvore t contendo Chave x.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Elemento* pesquisaSBB(ArvoreSBB *t, Chave x);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void ee(ArvoreSBB** ptr
*Função:Transformação esquerda-esquerda para manter propriedadas da árvore SBB.
*Entrada:Ponteiro para ArvoreSbb ptr.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void ee(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void dd(ArvoreSBB** ptr);
*Função:Transformação direita-direita para manter propriedadas da árvore SBB
*Entrada:Ponteiro para ArvoreSbb ptr.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void dd(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void ed(ArvoreSBB** ptr);
*Função:Transformação esquerda-direita para manter propriedadas da árvore SBB.
*Entrada:Ponteiro para ArvoreSbb ptr.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void ed(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void de(ArvoreSBB** ptr);
*Função:Transformação direita-esquerda para manter propriedadas da árvore SBB.
*Entrada:Ponteiro para ArvoreSbb ptr.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void de(ArvoreSBB** ptr);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void iInsere(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim);
*Função:Função auxiliar usada pela insereElemento.
*Entrada:Elemento r, Arvore SBB ptr e inteiros incli e fim.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void iInsere(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void iInsereAqui(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim);
*Função: Função auxiliar usada pela iInsere.
*Entrada:Elemento r, Arvore SBB ptr e inteiros incli e fim.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void iInsereAqui(Elemento* r, ArvoreSBB** ptr, int *incli, int *fim);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void insereElementoSBB(ArvoreSBB** t, Elemento *n);
*Função:Insere Elemento n na ArvoreSBB t.
*Entrada:ArvoreSBB t e Elementon.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void insereElementoSBB(ArvoreSBB** t, Elemento *n);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void inicializa(ArvoreSBB** raiz);
*Função:Inicializa a raiz da árvore com NULL.
*Entrada:Ponteiro para ArvoreSBB.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void inicializa(ArvoreSBB** raiz);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void imprimeArvoreSBB(ArvoreSBB* t);
*Função:Imprime ArvoreSBB.
*Entrada:ArvoreSBB t.
*Saída:Função void (Imprimi no stdout).
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprimeArvoreSBB(ArvoreSBB* t);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void apagaArvoreSBB(ArvoreSBB *t);
*Função:Desaloca ArvoreSBB t.
*Entrada:ArvoreSBB t.
*Saída:Função Void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaArvoreSBB(ArvoreSBB *t);


#endif
