/*
 ============================================================================
 Name        : PageRank.c
 Author      : Marcus Vinícius de Oliveira
 Version     :
 Copyright   : AEDs
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PageRank.h"

#define MAX 1001


double** alocarMatriz(int Linhas,int Colunas){

  int i,j;

  double **m = (double**)malloc(Linhas * sizeof(double*)); //Aloca um Vetor de Ponteiros

  for (i=0; i<Linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
       m[i] = (double*) malloc(Colunas * sizeof(double)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
       for (j = 0; j < Colunas; j++){ //Percorre o Vetor de Inteiros atual.
            m[i][j] = 0; //Inicializa com 0.
       }
  }
return m;
}

void liberaMatriz(double **matriz, int dimensao){
	int i;

	for (i=0; i<dimensao; i++){
		free (matriz[i]);
	}
	free(matriz);
}

void imprimeMatriz (double **matriz, int dimensao){
	int i, j;
	for (i=0; i<dimensao; i++){
		for (j=0; j<dimensao; j++){
			printf ("%.4lf ", matriz[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");
}

void substituiLinhas0 (double **matriz, int *vet_linhas, int dimensao){
	int i=0, j=0;

	for (i=0; i<dimensao;i++){
	    if (vet_linhas[i]==0)
	        for (j=0;j<dimensao; j++){
	            matriz[i][j]=1;
	        }
	}
}

void matrizEstocastica (double **matriz, int dimensao){
	int i=0, j=0;
	double soma_linha=0;
	double temp_estocastico=0;

	for (i=0; i<dimensao; i++){
	    for (j=0; j<dimensao; j++){
	        soma_linha += matriz[i][j];
	    }

	    temp_estocastico=1/soma_linha;

	    for (j=0; j<dimensao; j++){
	        if (matriz[i][j]==1)
	            matriz[i][j]=temp_estocastico;
	    }
	    temp_estocastico=0;
	    soma_linha=0;
	}
}

void gerarMatrizm (double **matriz_adjacencia, double **matriz_m, int dimensao, double damping_factor){
    int i=0, j=0;

    for (i=0; i<dimensao; i++){
        for (j=0; j<dimensao; j++){
            matriz_m[i][j]= ((1-damping_factor)*matriz_adjacencia[i][j])+(damping_factor*((float)1/dimensao));
        }
    }

}

void multiplicaMatriz (double **matriz_1, double **matriz_2, double **matriz_resultado, int dimensao){
	int i=0, j=0, k=0;

	for(i = 0; i < dimensao; i++) {
		for(j = 0; j < dimensao; j++) {
			for(k = 0; k < dimensao; k++) {
				matriz_resultado[i][j] += matriz_2[k][j]*matriz_1[i][k];
			}
		}
	}
}

void powMatriz (double **matriz_1, double **matriz_resultado, int dimensao, int expoente){

	double **matriz_temp; matriz_temp=alocarMatriz(dimensao, dimensao);
	int i=0, j=0;

    for(i=0; i<dimensao;i++){									//COPIA A MATRIZ m EM m2
        for(j=0;j<dimensao;j++){
            matriz_resultado[i][j]=matriz_1[i][j];
        }
    }

	for (int p=0; p<expoente; p++){

		multiplicaMatriz (matriz_1, matriz_resultado, matriz_temp, dimensao);

	    for(i=0; i<dimensao;i++){
	        for(j=0;j<dimensao;j++){
	            matriz_resultado[i][j]=matriz_temp[i][j];
	            matriz_temp[i][j]=0;
	        }
	    }
	}
	liberaMatriz(matriz_temp, dimensao);
}

double somatorioMatriz (double **matriz, int dimensao){
	double somatorio=0;
	int i, j;

	for (i=0; i<dimensao; i++){
		for (j=0; j<dimensao; j++){
			somatorio+=matriz[i][j]*matriz[i][j];
		}
	}
	return somatorio;
}

double** subtraiMatriz (double **matriz_1, double **matriz_2, double **matriz_resultado, int dimensao){
	int i, j;

	for(i=0; i<dimensao;i++){
	        for(j=0;j<dimensao;j++){
	            matriz_resultado[i][j]=matriz_1[i][j]-matriz_2[i][j];
	        }
	    }
	return matriz_resultado;
}

void convergirMatriz (double **matriz_1, double **matriz_resultado, int dimensao ){

	int i, j, m=2;
	double **matriz_m; matriz_m=alocarMatriz(dimensao, dimensao);
	double **matriz_mmenosum; matriz_mmenosum=alocarMatriz(dimensao, dimensao);
	double **matriz_aux; matriz_aux=alocarMatriz(dimensao, dimensao);
	double temp=1;

    for(i=0; i<dimensao;i++){									//COPIA A MATRIZ m EM m2
        for(j=0;j<dimensao;j++){
            matriz_m[i][j]=matriz_1[i][j];
            matriz_mmenosum[i][j]=matriz_1[i][j];
        }
    }

	/*powMatriz(matriz_1, matriz_m, dimensao, 2);

	subtraiMatriz(matriz_m, matriz_mmenosum, matriz_resultado, dimensao);
	temp=somatorioMatriz(matriz_resultado, dimensao);
	temp*=temp;*/

	while (temp > (10E-12)){

		powMatriz(matriz_1, matriz_m, dimensao, m);
		powMatriz(matriz_1, matriz_mmenosum, dimensao, m-1);
		m++;

		subtraiMatriz(matriz_m, matriz_mmenosum, matriz_aux, dimensao);
		temp=somatorioMatriz(matriz_aux, dimensao);


	    for(i=0; i<dimensao;i++){
	        for(j=0;j<dimensao;j++){
	        	matriz_resultado[i][j]=matriz_m[i][j];
	            matriz_m[i][j]=matriz_1[i][j];
	            matriz_mmenosum[i][j]=matriz_1[i][j];
	        }
	    }
	}



    liberaMatriz(matriz_aux, dimensao);
	liberaMatriz(matriz_m, dimensao);
	liberaMatriz(matriz_mmenosum, dimensao);
}

//"||M^m − M^n|| ≤ 10e−12
//0 0.1525
//1 0.1740
//2 0.1200
//3 0.2523
//4 0.3013
