/*
 ============================================================================
 Name        : TP3.c
 Author      : Marcus Vinícius de Oliveira
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "octree.h"

#define MAX 10
#define MAXX 1000


int main(void) {

	FILE* file;

	//file = stdin;
	file = fopen ("/home/marcus/in1.txt", "r");

	float arestaCuboLigante=0;							// Armazena valor da aresta do cubo ligante
	char id [MAX];										//na leitura, identificara se os dados a serem lidos serao de uma proteina, ligante, etc
	char aminoacido[MAX];								//os dados armazenados nessa variavel nao serao utilizados nesse tp. A varial existe apenas para efetivar a leitura da entrada
	//char idAtomoLigante [MAX];						//os dados armazenados nessa variavel nao serao utilizados nesse tp. A varial existe apenas para efetivar a leitura da entrada
	char ligante[3];									//armazena o nome do ligante

	Coordenadas *maiorVertice;
	maiorVertice = (Coordenadas*)malloc(sizeof(Coordenadas));
	Coordenadas *menorVertice;
	menorVertice = (Coordenadas*)malloc(sizeof(Coordenadas));
	Coordenadas *coordenadasParaInserir;
	coordenadasParaInserir = (Coordenadas*)malloc(sizeof(Coordenadas));

	Octree *octree;

	int interacoes=0, contLigante=0;
	Ligante listaLigantes[MAXX];



	fscanf (file, "%f ", &arestaCuboLigante);	// Leitura da aresta do ligante.
	fscanf (file, "%s", &id);	//Leitura do id.

	do{
		fscanf (file, "%s", &ligante);	//Leitura do ligante.
		fscanf (file, "%f  %f  %f ", &menorVertice->x , &menorVertice->y, &menorVertice->z);		//Leitura do menor vertice.
		fscanf (file, "%f  %f  %f ", &maiorVertice->x , &maiorVertice->y, &maiorVertice->z);		//Leitura do maior vertice.

		octree=alocaOctree(maiorVertice, menorVertice);

		fscanf (file, "%s", &id);	//Leitura do id.
		while (strlen(id)==8){	//Enquanto o id for == PROTEINA, lera os dados relativos a proteina.
			fscanf (file, "%s", &aminoacido);
			fscanf (file, "%f  %f  %f ", &coordenadasParaInserir->x , &coordenadasParaInserir->y, &coordenadasParaInserir->z); //teste

			insere (octree, coordenadasParaInserir);

			fscanf (file, "%s", &id);
		}

		while (strlen(id)==7){	//Enquanto o id for == LIGANTE, lera os dados relativos ao ligante.
			fscanf (file, "%s", &aminoacido);
			fscanf (file, "%f  %f  %f ", &coordenadasParaInserir->x , &coordenadasParaInserir->y, &coordenadasParaInserir->z); //teste


			Cubo *cuboLigante;
			//cuboLigante = alocaCubo ( coordenadasParaInserir, arestaCuboLigante);

			cuboLigante = (Cubo*)malloc(sizeof(Cubo));


			cuboLigante->origem.x = coordenadasParaInserir->x;
			cuboLigante->origem.y = coordenadasParaInserir->y;
			cuboLigante->origem.z = coordenadasParaInserir->z;


			cuboLigante->meiaDimensao = arestaCuboLigante/2;


			cuboLigante->verticeMax.x = cuboLigante->origem.x + cuboLigante->meiaDimensao;
			cuboLigante->verticeMax.y = cuboLigante->origem.y + cuboLigante->meiaDimensao;
			cuboLigante->verticeMax.z = cuboLigante->origem.z + cuboLigante->meiaDimensao;


			cuboLigante->verticeMin.x = cuboLigante->origem.x - cuboLigante->meiaDimensao;
			cuboLigante->verticeMin.y = cuboLigante->origem.y - cuboLigante->meiaDimensao;
			cuboLigante->verticeMin.z = cuboLigante->origem.z - cuboLigante->meiaDimensao;


			printf ("%f %f %f \n", cuboLigante->verticeMax.x, cuboLigante->verticeMax.y, cuboLigante->verticeMax.z);


			pontosDentroCubo (&(cuboLigante->verticeMin), &(cuboLigante->verticeMax), octree, &interacoes);





			fscanf (file, "%s", &id);
			//printf("%s\n\n\n", id);	//teste

		}






		char *l;
		l=ligante;

		listaLigantes[contLigante].nome = (char*)malloc(5,sizeof(char));

		//for (int i=0; i<4; i++){
		//	listaLigantes[contLigante].nome[i] = ligante[i];

		//}
		//strcpy(listaLigantes[contLigante].nome, ligante);

		listaLigantes[contLigante].nome = ligante;
		listaLigantes[contLigante].interacoes = interacoes;
		contLigante++;








		interacoes=0;
		if (strlen(id)<3)
			break;
	}while (id != "-1");

	contLigante=0;
	while (listaLigantes[contLigante].interacoes!=NULL){
		printf("%s %d \n\n",listaLigantes[contLigante].nome,  listaLigantes[contLigante].interacoes);
		contLigante++;
	}


	return EXIT_SUCCESS;
}
