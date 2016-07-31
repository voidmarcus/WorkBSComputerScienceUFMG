#ifndef READER
#define READER

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:int numeroLinhas(char* arg);
*Função:Contar o número de linhas que o arquivo possui
*Entrada:Endereço do arquivo
*Saída:Inteiro correspondente ao número de linhas
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int numeroLinhas(char* arg);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:Aluno** leituraArquivo(char* arg);
*Função:Ler o arquivo e armazenar os dados em um vetor.
*Entrada:Endereço do arquivo.
*Saída:Vetor tipo Aluno de ponteiros contendo os dados do arquivo
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Aluno** leituraArquivo(char* arg);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void apagaListaAlunos(char* arg, Aluno** listaAlunos)
*Função:apaga/desaloca vetor alocado na função anterior.
*Entrada:Vetor do tipo Aluno.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaListaAlunos(char* arg, Aluno** listaAlunos);

#endif
