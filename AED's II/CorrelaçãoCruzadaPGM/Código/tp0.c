#include <stdio.h>
#include <stdlib.h>
#include "tp0.h"

PGM* LePGM(char* entrada){
	// Declaracoes de variaveis: ----------------------------------------------------------------
	int i,j; 								//variaveis gernericas usadas para o for.
	char indicadorPGM[5];					//variavel que armazena a primeira linha da imagem PGM (indicadorPGM).

	PGM *imagem;							//estrutura PGM que sera retornada e sua
	imagem = (PGM*) malloc(sizeof(PGM));	//alocacao dinamica.

	// Abertura da entrada tipo FILE:-------------------------------------------------------------
	FILE* file;
	file = fopen(entrada, "r");

	// Leitura e atribuicao da entrada:-----------------------------------------------------------
	fscanf (file, "%s", &indicadorPGM);
	fscanf (file, "%d %d %hhu", &imagem->c, &imagem->l, &imagem->maximo);

	// A partir da leitura de dados, alocacao da matriz de dados no interior da estrutura PGM:-----
	imagem->dados = (unsigned char**)malloc(imagem->l * sizeof(unsigned char*));
	for(i=0; i<imagem->l; i++){
		imagem->dados[i] = (unsigned char*)malloc(imagem->c * sizeof(unsigned char));
		for (j=0;j<imagem->c;j++){
			imagem->dados[i][j] = 0;
		}
	}

	// Retorno da leitura e atribuicao da entrada --------------------------------------------------
	for(i=0;i<imagem->l;i++){
		for(j=0;j<imagem->c;j++){
			fscanf(file, "%hhu", &imagem->dados[i][j]);
		}
	}

	fclose(file);		// fechamento do arquivo de entrada

	return imagem;
}

void LiberaPGM (PGM *imagem){
	int i;

	for (i=0; i<imagem->l;i++){
		free (imagem->dados[i]);			//libera as linhas da matriz.
	}
	free(imagem->dados);					//libera a matriz (vetor de ponteiro).
}

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p){
	int i, j;
	int corCruzada = 0;

	for(i=p.x; i<(p.x + obj->l); i++){
		for(j=p.y; j<(p.y + obj->c); j++){
			corCruzada += obj->dados[i - p.x][j - p.y] * cena->dados[i][j];
		}
	}
	return corCruzada;
}

Ponto JanelaDeslizante(PGM *cena, PGM *obj){
	Ponto pontoAtual, pontoMatch;
	int i, j;
	int corCruzada = 0;
	int corTemporario = 0;

	for(i=0; i <= (cena->l - obj->l); i++){
		for(j=0; j <= (cena->c - obj->c); j++){
			pontoAtual.x = i; pontoAtual.y = j;
			corTemporario = CorrelacaoCruzada(cena, obj, pontoAtual);
			if(corTemporario > corCruzada){
				corCruzada = corTemporario;
				pontoMatch.y = j; pontoMatch.x = i;
			}
		}
	}

	return pontoMatch;
}


