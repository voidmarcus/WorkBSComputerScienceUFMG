

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double** alocarMatriz(int Linhas,int Colunas);

void liberaMatriz(double **matriz, int dimensao);

void imprimeMatriz (double **matriz, int dimensao);

void substituiLinhas0 (double **matriz, int *vet_linhas, int dimensao);

void matrizEstocastica (double **matriz, int dimensao);

void gerarMatrizm (double **matriz_adjacencia, double **matriz_m, int dimensao, double damping_factor);

void multiplicaMatriz (double **matriz_1, double **matriz_2, double **matriz_resultado, int dimensao);

void powMatriz (double **matriz_1, double **matriz_resultado, int dimensao, int expoente);

void convergirMatriz (double **matriz_1, double **matriz_resultado, int dimensao);

double** subtraiMatriz (double **matriz_1, double **matriz_2, double **matriz_resultado, int dimensao);
