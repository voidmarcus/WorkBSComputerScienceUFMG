/*
 ============================================================================
 Name        : TP1.c
 Author      : Marcus Vinicius de Oliveira
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "labirinto.h"


int main(int argc, char *argv[]){
	// Declaracao de variaveis, alocaoes dinamicas e atribuicoes =============================================================================
	int i, j, resultado;

	FILE *saida;

	Labirinto *lab;
	lab = LeLabirinto((char*)argv[1]); //atribuicao da struct lab atraves da funcao LeLabirinto.

	// Aloca Matriz Solucao e zera seus elementos
	int **sol=(int**)malloc(lab->N * sizeof(int*)); 	//Aloca um Vetor de Ponteiros.
  	for (i = 0; i < lab->N ; i++){ 						//Percorre as linhas do Vetor de Ponteiros.
       sol[i] = (int*) malloc(lab->N  * sizeof(int)); 	//Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < lab->N ; j++){ 					//Percorre o Vetor de Inteiros atual.
            sol[i][j] = 0; 								//Inicializa com 0.
       }
  	}


  	int x = (int)(argv[3][0] - '0'); //converte argv[3] em int
  	// Escolha entre Algoritmo recursivo ou interativo conforme parametro argv[3] e sua respectiva chamada ====================================

  	if (x==0){
  		resultado = CaminhaLabirintoRecursivo(lab, lab->x, lab->y, sol);
  	}
  	else
  		if(x==1){
  		resultado = CaminhaLabirintoIterativo(lab, lab->x, lab->y, sol);
  	}

  	// Gravando saida (Matriz solucao) do programa conforme parametro argv[2]===================================================================

  	saida = fopen(argv[2], "w");

  	if (resultado !=0){									// Caso exista caminho, grava-o no arquivo de saida
		for (i = 0; i < lab->N ; ++i){
				for (j = 0; j < lab->N ; ++j){
					fprintf(saida, "%d ",sol[i][j]);
				}
			fprintf(saida, "\n");
			}
  	}

  	else
  		fprintf(saida, "0");							// Caso nao exista caminho, grava "0" no arquivo de saida

	fclose(saida);

	// Liberacao das estruturas alocadas dinamicamente===========================================================================================

	// Liberar matriz sol.
	for (i=0; i<lab->N;i++){
		free (sol[i]);			//libera as linhas da matriz.
	}
	free(sol);					//libera a matriz (vetor de ponteiro).

	// Liberar struct lab.
	LiberaLabirinto(lab);


	// Retorno da main=============================================================================================================================

	return resultado;

}
