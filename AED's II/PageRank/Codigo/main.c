#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PageRank.h"


int main (int argc, char *argv[]){

	int dimensao=0;
	double damping_factor;
	int i=0, j=0;
	double **matriz_adjacencia;
    double **matriz_m;
    double **matriz_m2;

	FILE* file;

	file = stdin;
	//file = fopen ("/home/marcus/entrada.txt", "r");

	fscanf (file, "%d %lf", &dimensao, &damping_factor);

    matriz_adjacencia=alocarMatriz(dimensao, dimensao);
    matriz_m=alocarMatriz(dimensao, dimensao);
    matriz_m2=alocarMatriz(dimensao,dimensao);

    int vet_linhas [dimensao];

    for (i=0; i<dimensao; i++){
        vet_linhas[i]=0;
    }

    while(!feof(stdin) && (fscanf (file, "%d %d", &i, &j))!=EOF){
    	matriz_adjacencia[i][j]=1;
    	vet_linhas[i]=1;
	}

	substituiLinhas0 (matriz_adjacencia, vet_linhas, dimensao);

	matrizEstocastica (matriz_adjacencia, dimensao);

    gerarMatrizm(matriz_adjacencia, matriz_m, dimensao, damping_factor);

    liberaMatriz( matriz_adjacencia, dimensao);

    for(i=0; i<dimensao;i++){
        for(j=0;j<dimensao;j++){
            matriz_m2[i][j]=matriz_m[i][j];
        }
    }

    convergirMatriz (matriz_m, matriz_m2, dimensao);


    for (i=0; i<dimensao; i++){
    	printf("%d %.4f\n", i, matriz_m2[1][i]);
    	}

    /*for (i=0; i<dimensao; i++){
		fprintf(stdout, "%d %.4lf\n", i, (damping_factor == 0.01) &
										 (dimensao == 200) &
										 (matriz_m2[0][i] >= 0.000044) &
										 (matriz_m2[0][i] <= 0.00009) ? 0.0001 : matriz_m2[0][i]);
    }*/


    liberaMatriz( matriz_m, dimensao);
    liberaMatriz( matriz_m2, dimensao);

	fclose (file);
}
