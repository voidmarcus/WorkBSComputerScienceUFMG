#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "reader.h"

int numeroLinhas(char* arg){
	int linhas = 0;
	char caractere;

	FILE* file;
	file = fopen((char*)arg, "r");

	while (!feof (file)){
		caractere = fgetc(file);

		if (caractere == '\n'){		//Cada vez que é encontrado o caractere '\n' variavel li
			linhas++;				//nhas é incrementado.
		}
	}

	fclose(file);

	return linhas;
}


Aluno** leituraArquivo(char* arg){
	int i;
	char nome[40];
	int matricula;
	int numAlunos=(numeroLinhas(arg))/2; //conforme estrutura do arquivo dada na especificação.

	FILE* file;
	file = fopen((char*)arg, "r");

	Aluno **listaAlunos;
	listaAlunos = (Aluno**) malloc(numAlunos*sizeof(Aluno*));

	for(i=0;i<numAlunos; i++){
		fscanf(file, "%d:", &matricula);
		fgetc(file);					//Retirada do \n do buffer
		fgetc(file);					//Retirada do \n do buffer
		fscanf(file, "%[^\n]", nome);
		listaAlunos[i] = criaAluno(nome, matricula); //Cria Estrutura Aluno, conforme TAD aluno.
	}

	fclose(file);

	return listaAlunos;
}

void apagaListaAlunos(char* arg, Aluno** listaAlunos){
	int i;
	for (i=0; i<numeroLinhas(arg)/2; i++){	//Apaga cada lemento do vetor de ponteiros para Aluno.
		apagaAluno(listaAlunos[i]);			//*As estruturas Alunos são desalocadas dentro do TAD
	}										//das árvores.
	free(listaAlunos);
}
