#include <stdio.h>
#include <stdlib.h>
#include "tp0.h"



int main(int argc, char *argv[]){

	// Declaracoes e atribuicoes de variaveis: ---------------------------------------------------------
	Ponto pontoMaiorCor;
	FILE *saida;

	PGM *imagem;
	imagem = LePGM(argv[1]);

	PGM *objeto;
	objeto = LePGM(argv[2]);

	// Execucao do algoritmo (Chamada da funcao JanelaDeslizante):---------------------------------------
	pontoMaiorCor = JanelaDeslizante(imagem, objeto);

	// Liberacao das estruturas alocadas dinamicamente:--------------------------------------------------
	LiberaPGM(imagem);
	LiberaPGM(objeto);

	saida = fopen(argv[3], "w");
	fprintf(saida, "%d %d\n", pontoMaiorCor.y, pontoMaiorCor.x);
	fclose(saida);
}
