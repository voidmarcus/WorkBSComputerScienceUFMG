#ifndef BINARYTREE
#define BINARYTREE

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef Aluno Elemento;

typedef struct Arvore {
	struct Arvore* esq;
	struct Arvore* dir;
	Elemento* reg;
}Arvore;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:Arvore* criaArvore(Elemento* r);
*Função:Cria uma árvore com o elemento r sendo raíz.
*Entrada:Elemento r.
*Saída:Endereço contendo raiz da arvore
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Arvore* criaArvore(Elemento* r);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:pesquisa(Arvore *t, Chave x)
*Função:Pesquisa na árvore o elemento com chave x.
*Entrada:Arvore e chave.
*Saída:Caso exista, retorna endereço da Arvore t contendo Chave x.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Elemento* pesquisa(Arvore *t, Chave x);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:insereElemento(Arvore* t, Elemento *n)
*Função:Insere elemento n na árvore t.
*Entrada:Arvore t e Elemento n.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void insereElemento(Arvore* t, Elemento *n);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:removeDaArvore(Arvore* t, Chave c)
*Função:Remove Elemento que contem Chave C da Arvore.
*Entrada:Arvore t e Chave c.
*Saída:Endereço da Arvore t sem elemento contendo Chave c.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Arvore* removeDaArvore(Arvore* t, Chave c);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:Arvore* achaMenor(Arvore* t)
*Função:Encontra o menor elemento da árvore t.
*Entrada:Arvore t.
*Saída:Retorna endereço de Arvore t contendo menor elemento de t inicial.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Arvore* achaMenor(Arvore* t);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void imprimeArvore(Arvore *t);
*Função:Imprimi Arvore t atravéz da função imprimiAluno.
*Entrada:Arvore t.
*Saída:Função void (imprensão da Arvore no stdout).
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprimeArvore(Arvore *t);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void apagaArvore(Arvore *t);
*Função:Desaloca Arvore t.
*Entrada:Arvore t.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaArvore(Arvore *t);


#endif
