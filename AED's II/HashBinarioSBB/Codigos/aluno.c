#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"
#include "aluno.h"

Aluno* criaAluno(char* n, Chave mat){
	int len = strlen(n)+1;
	Aluno *aluno;
	aluno = (Aluno*) malloc(sizeof(Aluno));

	char *nome=malloc(len*sizeof(char));

	strcpy(nome, n);

	aluno->matricula = mat;
	aluno->nome=nome;

	return aluno;
}

void apagaAluno(Aluno* a){
	free(a->nome);
	free(a);
}

void imprimeAluno(Aluno* a){
	printf("(%d) %s\n", a->matricula, a->nome);
}
