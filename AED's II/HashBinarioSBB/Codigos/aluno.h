#ifndef ALUNO
#define ALUNO

typedef int Chave;

typedef struct Aluno{
	char* nome;
	Chave matricula;
}Aluno;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:criaAluno(char* n, Chave mat);
*Função:Cria estrutura aluno.
*Entrada:Nome do Aluno e Mátricula.
*Saída:Endereço para estrutura aluno criada.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Aluno* criaAluno(char* n, Chave mat);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:void apagaAluno(Aluno* a)
*Função:Apaga/desaloca estrutura Aluno e todos os seus dados.
*Entrada:Endereço da estrutura Aluno.
*Saída:Função Void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void apagaAluno(Aluno* a);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Protótipo:imprimeAluno(Aluno* a)
*Função:Imprime estrutura aluno na stdio na forma: (MATRICULA) NOME COMPLETO
*Entrada: Estrutura Aluno.
*Saída:Função void.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void imprimeAluno(Aluno* a);

#endif
