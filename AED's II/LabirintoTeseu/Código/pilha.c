#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "labirinto.h"

void FPVazia(TipoPilha *Pilha) {

	Pilha->Topo = (Apontador)malloc(sizeof(Celula));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;

}

int Vazia(TipoPilha *Pilha){
	return (Pilha->Topo == Pilha->Fundo);
}

void Empilha(TipoItem x, TipoPilha *Pilha){
	Apontador Aux;
	Aux = (Apontador) malloc(sizeof(Celula));
	Aux->Item = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item){
   Apontador q;

   if (Vazia(Pilha)==1){
      printf(" Erro pilha vazia\n");
      return;
   }

   q = Pilha->Topo;
   Pilha->Topo = q->Prox;
   *Item = q->Prox->Item;
   free(q);
   Pilha->Tamanho--;
}

int Tamanho(TipoPilha *Pilha){
	return (Pilha->Tamanho);
}
