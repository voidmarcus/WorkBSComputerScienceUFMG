typedef int TipoChave;

typedef struct{
	int x;
	int y;
}TipoItem;

typedef struct Celula *Apontador;

typedef struct Celula{
	TipoItem Item;
	Apontador Prox;
}Celula;

typedef struct{
	Apontador Fundo, Topo;
	int Tamanho;
}TipoPilha;


/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: void FPVazia(TipoPilha *Pilha)
Função: Faz uma pilha vazia.
Entrada: Ponteiro TipoPilha.
Saída: Uma pilha vazia.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void FPVazia(TipoPilha *Pilha);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: int Vazia(TipoPilha *Pilha)
Função: Verifica se a pilha esta vazia.
Entrada: Ponteiro para pilha.
Saída: Retorna true se a pilha esta vazia, caso contrario retorna false.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int Vazia(TipoPilha *Pilha);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo:void Empilha(TipoItem x, TipoPilha *Pilha)
Função: Insere o TipoItem x no topo da pilha.
Entrada: TipoItem x e ponteiro para pilha.
Saída: Nao ha saida.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void Empilha(TipoItem x, TipoPilha *Pilha);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo:void Desempilha(TipoPilha *Pilha, TipoItem *Item)
Função: Desempilha o elemento Item no topo da pilha.
Entrada:Ponteiro para pilha e ponteiro para TipoItem
Saída: Nao ha saida.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void Desempilha(TipoPilha *Pilha, TipoItem *Item);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: int Tamanho(TipoPilha *Pilha)
Função: Retorna o numero de itens da pilha.
Entrada: Ponteiro para TipoPilha.
Saída: Retorna o numero de itens da pilha.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int Tamanho(TipoPilha *Pilha);
