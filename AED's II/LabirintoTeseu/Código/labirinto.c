#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "labirinto.h"

Labirinto *LeLabirinto(char *entrada){
	// Declaracoes de variaveis============================================================
	int i,j;
	Labirinto *lab;
	lab = (Labirinto*) malloc(sizeof(Labirinto));

	// Abertura do arquivo passado por parametro===========================================
	FILE* file;
	file = fopen(entrada, "r");

	// Leitura do "cabecalho" do arquivo===================================================
	fscanf(file, "%d %d %d %d %d", &lab->N, &lab->x, &lab->y, &lab->sx, &lab->sy);

	// Apos leitura do cabecalho, Alocacao da matriz mapa dentro da struct labirinto
	// bem como a atribuicao de 0 em seus elementos.=======================================
	lab->mapa = (unsigned char**) malloc(lab->N * sizeof(unsigned char*));
	for(i=0; i<lab->N; i++){
		lab->mapa[i] = (unsigned char*) malloc(lab->N * sizeof(unsigned char));
		for(j=0; j<lab->N; j++){
			lab->mapa[i][j] = 0;
		}
	}


	// Retomada da leitura do arquivo - leitura do mapa=====================================
	for(i=0; i<lab->N; i++){
		for(j=0; j<lab->N; j++){
			fscanf(file, "%hhu", &lab->mapa[i][j]);
		}
	}

	fclose(file); // Fechamento do arquivo.

	return lab;
}

void LiberaLabirinto(Labirinto* lab){
	int i;

	for (i=0; i<lab->N;i++){
			free (lab->mapa[i]);		//libera as linhas da matriz.
		}
	free(lab->mapa);					//libera a matriz (vetor de ponteiro).

	free(lab);							//libera  a struct lab.
}

int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y, int ** sol){
	if(x==lab->sx && y==lab->sy){
		sol[x][y]=1;
		return 1;
	}
	else

		if(x<lab->N && y<lab->N){	// Verifica se coordenadas estao dentro do labirinto.
			if(lab->mapa[x][y]==0 && sol[x][y]==0){
				sol[x][y]=1;
			 	if (CaminhaLabirintoRecursivo(lab, x+1, y, sol))
					return 1;
				else
					if (CaminhaLabirintoRecursivo(lab, x, y+1, sol))
						return 1;
				else
					if (CaminhaLabirintoRecursivo (lab, x-1, y, sol))
						return 1;
				else
					if (CaminhaLabirintoRecursivo(lab, x, y-1, sol))
						return 1;

				sol[x][y]=0;
			}
		}
	return 0;
}

int CaminhaLabirintoIterativo(Labirinto* lab, int x, int y, int ** sol){
	// Declaracoes de variaveis auxiliades ================================================
	int i, j;
	int flag = 0;
	TipoItem itemAux;

	// Criacao de uma pilha que guarda posicoes do caminho ================================

	TipoPilha pilha;
	FPVazia(&pilha);


	// Marca a celula de entrada do labirinto como visitada ===============================
	if (lab->mapa[x][y]==0 && sol[x][y]==0){

		itemAux.x=x;
		itemAux.y=y;
		Empilha(itemAux, &pilha);

		sol[x][y]=1;
	}

	// Laco - Enquanto posicao atual diferente da posicao da espada =======================
	while(x!=lab->sx || y!=lab->sy){

			if(x<lab->N && y<lab->N){ // Verifica se coordenadas estao dentro do labirinto.

				// Percorre o labirinto
				if (lab->mapa[x+1][y]==0 && sol[x+1][y]==0 && flag==0 && x+1<lab->N){
					x++;

					itemAux.x=x;
					itemAux.y=y;
					Empilha(itemAux, &pilha);

					sol[x][y]=1;
					flag=1;
				}
				else
					if (lab->mapa[x][y+1]==0 && sol[x][y+1]==0 && flag==0 && y+1<lab->N){
						y++;

						itemAux.x=x;
						itemAux.y=y;
						Empilha(itemAux, &pilha);

						sol[x][y]=1;
						flag=1;
				}
				else
					if (lab->mapa[x-1][y]==0 && sol[x-1][y]==0 && flag==0 && x-1<lab->N){
						x--;

						itemAux.x=x;
						itemAux.y=y;
						Empilha(itemAux, &pilha);

						sol[x][y]=1;
						flag=1;
					}
				else
					if (lab->mapa[x][y-1]==0 && sol[x][y-1]==0 && flag==0 && y-1<lab->N){
						y--;

						itemAux.x=x;
						itemAux.y=y;
						Empilha(itemAux, &pilha);

						sol[x][y]=1;
						flag=1;
					}

				else
					// Caso nao tenha caminho, entao volta!
					if(flag==0){
						itemAux.x=x;
						itemAux.y=y;
						Desempilha(&pilha, &itemAux);

						flag=1;

						x = pilha.Topo->Item.x;
						y = pilha.Topo->Item.y;
						// Caso volte ate o comeco, entao nao existe caminho.
						if (x==lab->x && y==lab->y){
							itemAux.x=x;
							itemAux.y=y;
							Desempilha(&pilha, &itemAux);

							for(i=0; i<lab->N; i++){
								for(j=0; j<lab->N; j++)
									sol[i][j]=0;
							}

							while(Vazia(&pilha)==0){
								sol[pilha.Topo->Item.x][pilha.Topo->Item.y]=1;
								itemAux.x=x;
								itemAux.y=y;
								Desempilha(&pilha, &itemAux);
							}

							free(pilha.Fundo);
							return 0;
						}
					}
			}
			//Caso nao tenha caminho, entao volta!
			if(flag==0){
				itemAux.x=x;
				itemAux.y=y;
				Desempilha(&pilha, &itemAux);

				flag=1;

				x = pilha.Topo->Item.x;
				y = pilha.Topo->Item.y;

				if (x==lab->x && y==lab->y)
					free(pilha.Fundo);
					return 0;
				}

		flag=0;
	}

	for(i=0; i<lab->N; i++){
		for(j=0; j<lab->N; j++)
			sol[i][j]=0;
	}
	while(Vazia(&pilha)==0){
		sol[pilha.Topo->Item.x][pilha.Topo->Item.y]=1;

		itemAux.x=x;
		itemAux.y=y;
		Desempilha(&pilha, &itemAux);
	}
	free(pilha.Fundo);
	return 1;
}
