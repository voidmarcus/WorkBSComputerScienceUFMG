#ifndef HASH
#define HASH

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "sbb.h"

typedef struct Hash{
	Arvore** hash;
	ArvoreSBB** hashSBB;
	int tam;
	int nElem;
}Hash;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:int funcaoHash(Elemento *ele, Hash *h);
*Função:Dado um Elemento, retorna seu hash.
*Entrada:Elemento que deseja o hash e a tabela hash.
*Saída:Inteiro com o hash do Elemento.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int funcaoHash(Elemento *ele, Hash *h);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:Hash* criaHash(int t, int boolSBB);
*Função:Inicializa tabela Hash com tamanho e tipo de tratamento de coli passados (aloca).
*Entrada:Inteiro contendo tamanho da Hash e inteiro indicando qual árvore será utilizada nas coli.
*Saída:Endereço da tabela hash.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Hash* criaHash(int t, int boolSBB);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void apagaHash(Hash* h, int boolSBB);
*Função:Desaloca Hash h, incluindo os elementos arvores.
*Entrada:Hash h e um inteiro indicando qual árvore foi utilizada.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaHash(Hash* h, int boolSBB);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void insereNaHash(Hash* h, Elemento* x, int boolSBB);
*Função:Insere um Elemento na Hash.
*Entrada:Hash h, Elemento x a ser inserido, inteiro indicando qual árvore será utilizada nas coli.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void insereNaHash(Hash* h, Elemento* x, int boolSBB);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:Elemento * obtemDaHash(Hash* h, Chave c);
*Função:Obtem um Elemento da Hash dada sua chave.
*Entrada:Hash h e Chave c a ser buscada.
*Saída:Endereço do elemento contendo a chave, caso ele exista.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Elemento * obtemDaHash(Hash* h, Chave c, int boolSBB);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void imprime(Hash* h, int boolSBB);
*Função:Imprimi os elementos da tabela Hash (As arvores que ela contém.
*Entrada:Hash h e inteiro indicando qual árvore será utilizada nas coli.
*Saída:Função void (Imprimi Hash no stdout).
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprime(Hash* h, int boolSBB);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:int obtemNumElem(Hash* h);
*Função:Retorna o número de elementos inseridos até o momento.
*Entrada:Hash h.
*Saída:Reorna inteiro contendo o número de elementos inseridos na Hash.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int obtemNumElem(Hash* h);

#endif
