 /*
 ============================================================================================================
 Name        : TP2 - AEDsII
 Author      : Marcus Vinicius de Oliviera
 Version     : 1.7
 Description : Recebe dados de aluno como entrada os distribui por uma tabela Hash que resolve colisão utili
 	 	 	   zando árvore binária ou SBB.
 ============================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hash.h"
#include "sbb.h"
#include "binaryTree.h"
#include "aluno.h"
#include "reader.h"

int main(int argc, char *argv[]) {
	//Para medir o tempo Pt1
	long double tempo;
	clock_t t_ini, t_fim;
	t_ini = clock();

	//Declaração e atribuições de variaveis==================================================================
	int i;
	int boolSBB = atoi(argv[4]); // Variavel responsavel pela escolha do tipo de arvore a ser usada
	int tamHash = atoi(argv[3]); // Guarda tamanho do Hash. Parametro para variavel

	Aluno **listaAlunos = leituraArquivo(argv[1]); //Lê o arquivo e armazena a lista de Alunos no vetor

	Hash* h = criaHash(tamHash, boolSBB); 	// Cria o hash de acordo com os parametros passados no argv



	//Chamada do algoritmo===================================================================================

	//Lê o vetor de Alunos e insere cada elemento na Hash
	for (i=0; i<numeroLinhas(argv[1])/2; i++){
		insereNaHash(h, listaAlunos[i], boolSBB);
	}

	//Imprenssão dos resultados =============================================================================
	close(1);						// Fecha stdout
	stdout = fopen(argv[2], "w"); 	// Abre arquivo para 'substituir' stdout

	imprime(h,boolSBB);

	//Libera a memória========================================================================================
	apagaHash(h, boolSBB);

	apagaListaAlunos(argv[1], listaAlunos);

	fclose(stdout);

	//Para medir o tempo Pt2==================================================================================
	t_fim = clock();
	tempo = (t_fim - t_ini)/CLOCKS_PER_SEC;
	/*
	 *Descomente as linhas 65 e 66 para imprimir o tempo gasto durante a execução do programa
	 *Lembre-se que o stdout está setado para o arquivo a ser imprimido.
	 */
	//printf("\n===================================\nTempo = %Lf\nAquivo = %s\nTamanho Hash = %d \nArvore tipo "
	//		"= %d\n=================================\n:", tempo, argv[1], tamHash, boolSBB);

	return EXIT_SUCCESS;
}
