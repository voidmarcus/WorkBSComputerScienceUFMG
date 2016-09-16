#ifndef TRIE
#define TRIE

#include <stdio.h>
#include <stdlib.h>
//#include "trie.c"

typedef int valorTrie;

typedef struct tNode{
  char chave;
  int valor;
  struct tNode *prox;
  struct tNode *ante;
  struct tNode *filho;
  struct tNode *pai;
} trieNode;


/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void CriaTrie(trieNode **raiz);
*Função:Cria Raiz de uma Trie
*Entrada:Ponteiro de Ponteiro trieNode Nullo
*Saída:Função void | Ponteiro da entrada aponta para uma raiz Trie
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void CriaTrie(trieNode **raiz);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void DesalocaTrie(trieNode* raiz);
*Função:Desaloca por completo a Trie
*Entrada:Ponteiro para raiza da Trie
*Saída:Função void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void DesalocaTrie(trieNode* raiz);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void AddTrie(trieNode **raiz, char *key, int data);
*Função:Adiciona uma chave e sua dada na Trie
*Entrada:Ponteiro de Ponteiro da raiz da Trie
*Saída:Função void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void AddTrie(trieNode **raiz, char *key, int data);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void ComputaTexto(trieNode *raiz, const char *chave);
*Função: Caso a chave de entrada esteja na trie, incrementa data da chave
*Entrada:Ponteiro da raiz da Trie, chave a ser verificada
*Saída:Função void
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void ComputaTexto(trieNode *raiz, const char *chave);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:int ProcuraValor(trieNode *raiz, const char *chave);
*Função:Retorna o valor da data da chave, caso esteja presente no texto
*Entrada:Ponteiro da raiz da Trie, chave a ser verificada a data
*Saída:valor da data da chave
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int ProcuraValor(trieNode *raiz, const char *chave);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:trieNode* ProcuraTrie(trieNode *raiz, const char *key);
*Função:Procura por uma chave na trie, caso encontrada retorna a folha correspondente
*Entrada:Ponteiro da raiz da Trie, chave a ser verificada
*Saída:retorna a folha correspondente a chave
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
trieNode* ProcuraTrie(trieNode *raiz, const char *key);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:ImprimiTrie(trieNode *raiz, int lvl);
*Função:Imprime de forma improvisada a trie (usada durante os testes)
*Entrada:rais da trie e lvl defaut 0
*Saída:Imprime Trie saida padrão
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void ImprimiTrie(trieNode *raiz, int lvl);


#endif
