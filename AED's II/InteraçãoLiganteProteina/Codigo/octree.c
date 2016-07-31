#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "octree.h"


bool ehFolha (Octree *no){
	for(int i=0; i<8; ++i)				//Se tem filho, retorna falso.
		 if(no->filhos[i] != NULL)
			 return false;
		 return true;
}

void imprimiOctree (Octree *octree){

	int i; static int nivel=0;
	nivel ++;


	if(ehFolha(octree)){
		if(octree->data!=NULL){
			printf ("Coordenada do atomo %f  %f  %f \n", octree->data->x, octree->data->y, octree->data->z);
			printf ("Coordenada da origem %f  %f  %f \n\n", octree->origem.x, octree->origem.y, octree->origem.z);
			return;}
	} else{

		for(i=0; i<8;i++){
			imprimiOctree(octree->filhos[i]);
			printf("Filho %d 		Nivel %d \n", i, nivel/8);

			}
		}

	nivel--;

	}

int qualOctante (Octree *octree, Coordenadas *coordenada){
	int octante=0;
	if(coordenada->x >= octree->origem.x) octante |= 4;
	if(coordenada->y >= octree->origem.y) octante |= 2;
	if(coordenada->z >= octree->origem.z) octante |= 1;
	return octante;
}

Octree* alocaOctree(Coordenadas *maiorVertice, Coordenadas *menorVertice){
	Octree *octree;
	octree = (Octree*)malloc(sizeof(Octree));

	//printf("Alocou um no na Octree\n");		//####TESTE#####

	octree->origem.x = (maiorVertice->x + menorVertice->x)/2;
	octree->origem.y = (maiorVertice->y + menorVertice->y)/2;
	octree->origem.z = (maiorVertice->z + menorVertice->z)/2;

	//printf ("origem %f  %f  %f \n", octree->origem.x, octree->origem.y, octree->origem.z);


	//long float long float long float float x= maiorVertice->x - menorVertice->x, y= maiorVertice->y - menorVertice->y, z= maiorVertice->z - menorVertice->z;
	//long float long float long float float meiaDimen = sqrtf ( powf(x,2) + powf(y,2) + powf(z,2));



	octree->meiaDimensao.x = fabsl( ((menorVertice->x) - (maiorVertice->x))/2);
	octree->meiaDimensao.y = fabsl( ((menorVertice->x) - (maiorVertice->x))/2);
	octree->meiaDimensao.z = fabsl( ((menorVertice->x) - (maiorVertice->x))/2);

	octree->verticeMax.x = maiorVertice->x;
	octree->verticeMax.y = maiorVertice->y;
	octree->verticeMax.z = maiorVertice->z;

	//printf ("verticeMax %f  %f  %f \n", octree->verticeMax.x, octree->verticeMax.y, octree->verticeMax.z);


	octree->verticeMin.x = menorVertice->x;
	octree->verticeMin.y = menorVertice->y;
	octree->verticeMin.z = menorVertice->z;

	//printf ("verticeMIn %f  %f  %f \n\n\n\n ", octree->verticeMin.x, octree->verticeMin.y, octree->verticeMin.z);


	for(int i=0; i<8; ++i)
		octree->filhos[i]=NULL;

	//getchar();

	return octree;
}

void insere (Octree *no, Coordenadas *pontos){
	int i, octante;

	if(ehFolha(no)){
		if(no->data==NULL){
			no->data = (Coordenadas*)malloc(sizeof(Coordenadas));
			*(no->data)=*pontos;
			//printf("passei no folha dataNull");
			return;
			//printf("ta retornando nao");

		}else {
			//printf (" data %f  %f  %f  ----  \n", no->data->x,no->data->y,no->data->z);
			Coordenadas *oldPoint;
			oldPoint = (Coordenadas*)malloc(sizeof(Coordenadas));
			*(oldPoint)=*(no->data);
			//oldPoint->x = no->data->x;
			//oldPoint->y = no->data->y;
			//oldPoint->z = no->data->z;
			free(no->data);
			no->data=NULL;

			//printf (" data %f  %f  %f  ----  \n", no->data->x,no->data->y,no->data->z);
			//printf (" atomo oldPoint %f  %f  %f  ----  \n", oldPoint->x, oldPoint->y,oldPoint->z);
			//printf (" atomo pontos %f  %f  %f  ----  \n", pontos->x, pontos->y,pontos->z);
			//printf (" atomo oldpoint %f  %f  %f  ----  \n\n", oldPoint->x, oldPoint->y,oldPoint->z);


			for(i=0; i<8;i++){
				Coordenadas novaOrigem = no->origem;

				Coordenadas *maiorVertice;
				maiorVertice = (Coordenadas*)malloc(sizeof(Coordenadas));
				Coordenadas *menorVertice;
				menorVertice = (Coordenadas*)malloc(sizeof(Coordenadas));

				/*
				novaOrigem.x += (no->meiaDimensao.x/2) * (i==4 ||i==5 ||i==6 ||i==7 ? 1.f : -1.f);
				novaOrigem.y += (no->meiaDimensao.y/2) * (i==2 ||i==3 ||i==6 ||i==7 ? 1.f : -1.f);
				novaOrigem.z += (no->meiaDimensao.z/2) * (i==1 ||i==3 ||i==5 ||i==7 ? 1.f : -1.f);
				*/
				novaOrigem.x += (no->meiaDimensao.x) * (i&4 ? .5f : -.5f);
				novaOrigem.y += (no->meiaDimensao.y) * (i&2 ? .5f : -.5f);
				novaOrigem.z += (no->meiaDimensao.z) * (i&1 ? .5f : -.5f);

				maiorVertice->x = novaOrigem.x + (no->meiaDimensao.x/2);
				maiorVertice->y = novaOrigem.y + (no->meiaDimensao.y/2);
				maiorVertice->z = novaOrigem.z + (no->meiaDimensao.z/2);

				menorVertice->x = novaOrigem.x - (no->meiaDimensao.x/2);
				menorVertice->y = novaOrigem.y - (no->meiaDimensao.y/2);
				menorVertice->z = novaOrigem.z - (no->meiaDimensao.z/2);

				//printf("%f  passei aqui: antes do aloca do insere\n", menorVertice->x);		//####TESTE#####


				no->filhos[i] = alocaOctree(maiorVertice, menorVertice);


				free(maiorVertice);
				free(menorVertice);

			}

			//printf("#####Sai do for#####\n");
			//getchar();

			octante = qualOctante(no, oldPoint);
			//printf ("-------------------octante oldPoint %d --------------------\n", octante);
			insere (no->filhos[octante], oldPoint);

			//printf("depois do octante 1\n");


			octante = qualOctante(no, pontos);
			//printf ("-------------------octante pontos   %d---_______------------\n", octante);
			//printf (" origem %f  %f  %f  ---- meiaDimensao %f  \n",no->filhos[octante]->origem.x ,no->filhos[octante]->origem.y, no->filhos[octante]->origem.z , no->filhos[octante]->meiaDimensao.x);
			//printf (" atomo 1 %f  %f  %f  ----  \n", oldPoint->x, oldPoint->y,oldPoint->z);
			//printf (" atomo 2 %f  %f  %f  ----  \n", pontos->x, pontos->y,pontos->z);

			//getchar();
			insere (no->filhos[octante], pontos);

			//printf("depois do octante 2 \n");

			free(oldPoint);

		}
	} else{
		octante = qualOctante(no, pontos);
		insere (no->filhos[octante], pontos);

	}
}

void pontosDentroCubo (Coordenadas *verticeMin, Coordenadas *verticeMax, Octree *octree,int *contador){
	int i;
	//*contador = *contador +1;

	//printf("%f %f %f\n" , verticeMin->x, verticeMin->y, verticeMin->z);

	if (ehFolha(octree)){
		if(octree->data!=NULL) {
			if (octree->data->x > verticeMax->x || octree->data->y > verticeMax->y || octree->data->z > verticeMax->z) return;
			if (octree->data->x < verticeMin->x || octree->data->y < verticeMin->y || octree->data->z < verticeMin->z) return;
			*contador = *contador +1;;
		}
	}else {
		for(i=0; i<8; i++){
			if(octree->filhos[i]->verticeMax.x < verticeMin->x || octree->filhos[i]->verticeMax.y < verticeMin->y || octree->filhos[i]->verticeMax.z < verticeMin->z) continue;
			if(octree->filhos[i]->verticeMin.x > verticeMax->x || octree->filhos[i]->verticeMin.y > verticeMax->y || octree->filhos[i]->verticeMin.z > verticeMax->z) continue;
			pontosDentroCubo (verticeMin, verticeMax, octree->filhos[i], &*contador);
		}
	}
}

Cubo* alocaCubo(Coordenadas *atomoLigante, float arestaCuboLigante){
	Cubo *cuboLigante;
	cuboLigante = (Cubo*)malloc(sizeof(Cubo));

	//*(cuboLigante->origem) = *atomoLigante;

	cuboLigante->meiaDimensao = arestaCuboLigante/2;

	cuboLigante->origem.x = atomoLigante->x;
	cuboLigante->origem.y = atomoLigante->y;
	cuboLigante->origem.z = atomoLigante->z;


	cuboLigante->verticeMax.x = cuboLigante->origem.x + cuboLigante->meiaDimensao;
	cuboLigante->verticeMax.y = cuboLigante->origem.y + cuboLigante->meiaDimensao;
	cuboLigante->verticeMax.z = cuboLigante->origem.z + cuboLigante->meiaDimensao;


	cuboLigante->verticeMin.x = cuboLigante->origem.x - cuboLigante->meiaDimensao;
	cuboLigante->verticeMin.y = cuboLigante->origem.y - cuboLigante->meiaDimensao;
	cuboLigante->verticeMin.z = cuboLigante->origem.z - cuboLigante->meiaDimensao;

	return cuboLigante;
}







/*
 * Nós estamos em um nó interior da árvore. Iremos verificar
 * para ver se a caixa delimitadora consulta encontra-se fora das octantes deste nó.

Calcule os min / max cantos deste octant criança

Se o retângulo de consulta é fora da caixa delimitadora da criança, em seguida, continuar

Neste ponto, determinamos que essa criança está cruzando caixa delimitadora a consulta
 *
 *
 *
child:					0 1 2 3 4 5 6 7
				x:      - - - - + + + +
				y:      - - + + - - + +
				z:      - + - + - + - +
*/


