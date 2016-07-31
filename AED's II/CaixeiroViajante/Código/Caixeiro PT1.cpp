//============================================================================
// Name        : Caixeiro.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define MAX 2147483647

using namespace std;

typedef struct{
    float x;
    float y;
    int cit;
} Cidades;

typedef struct{
	int *ciclo;
	float custo;
}Ciclo;

Ciclo menor;
char *saida;

void melhor_ciclo(Cidades *v, int size, float c )
{
	Ciclo atual;
	atual.ciclo = new int[size];
	for (int i=0; i<size; i++)
	{
		atual.ciclo[i]=v[i].cit;
	}
	atual.custo=c;

	static int cont=0;
	if (cont==0)
	{
		menor=atual;
		cont++;
	}else


	if (atual.custo<menor.custo)
		menor=atual;
}

void solucao_otima(int size)
{

	cout<<"================================================================================================"<<endl;
	cout << "A solução ótima para essa instância é:"<< endl;
	for (int i=0;i<size;i++)
		{
			cout << menor.ciclo[i] << " ";
		}
		cout << menor.ciclo[0] <<"  Custo = $"<<menor.custo << endl;

	cout<<"================================================================================================"<<endl;
}

float Dist(Cidades a, Cidades b)
{
  float dx = a.x - b.x;
  float dy = a.y - b.y;
  return sqrt(pow (dx,2) + pow (dy,2));
}

float DistTotal(Cidades *v, int size)
{
	int i;
	float total = 0;

	for (i=0; i+1<size;i++)
	{
		total+= Dist (v[i], v[i+1]);
	}
	total+=Dist (v[i], v[0]); //retorno para cidade fixada
	return total;
}

int fatorial(int x)
{
	if(x == 0)
		return 1;
	return x*fatorial(x-1);
}

void print(Cidades *v, int size)
{
	static float cont=1;
	static int t=0;
	static FILE* f;
	if (v != 0)
	{
		if (t==0)
		{
			f = fopen (saida, "w");
			fprintf (f, "%d \n", fatorial(size-1));
			t=1;
			fclose (f);
		}

		f = fopen (saida, "a");
		for (int i = 0; i < size; i++)
		{
			fprintf(f, "%d ", v[i].cit );
		}
		fprintf(f, "%d ", v[0].cit );
		float dis = DistTotal(v, size);
		fprintf(f, "= $%f", dis);
		fprintf(f, "\n");


		fclose (f);
		melhor_ciclo(v,size,dis);


		float n= cont*100/(fatorial(size-1));
		//std::cout.precision(3);
		cout <<"Processos em: " << n<<"%"<<endl;
		cont++;
		system("clear"); //cls para win
	}
}

void swap(Cidades *v, const int i, const int j)
{
	Cidades t;
	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void rotateLeft(Cidades *v, const int start, const int n)
{
	Cidades tmp = v[start];
	for (int i = start; i < n-1; i++)
	{
		v[i] = v[i+1];
	}
	v[n-1] = tmp;
}

void permute(Cidades *v, const int start, const int n)
{
	print(v, n);
	if (start < n)
	{
		int i, j;
		for (i = n-2; i >= start; i--)
		{
			for (j = i + 1; j < n; j++)
			{
				swap(v, i, j);
				permute(v, i+1, n);
			}
			rotateLeft(v, i, n);
		}
	}
}

float gap (float heuristica)
{
	return ((heuristica-menor.custo)/menor.custo)*100;
}

void Visitou (int adjacente[][6],int zerar, int size)
{
	for(int i=0; i<size; i++)
		adjacente [i][zerar]=1;
}

void Vizinho_proximo (Cidades *v, int size)
{

	float matriz [size][size];
	int adjacente [size][size];

	for (int i=0; i<size;i++)
		for (int j=0; j<size;j++)
			{
				matriz [i][j] = Dist(v[i], v[j]);
				adjacente[i][j]=0;
				adjacente[i][i]=1;
			}

	int i=0, j=0;
	float soma_menor=0;
	int caminho[size+1];
	caminho[0]=0;
	int cont=0;
	float menor;
	static int temp=0;

	while (cont<size)
	{
		menor=MAX;
		for(int k=0; k<size; k++)
			adjacente [k][i]=1;

		if (cont==size-1)
		{
			for(int k=0; k<size; k++)
				adjacente [k][0]=0;
		}

		for (j=0; j<size; j++)
		{
			if (matriz [i][j] < menor && adjacente [i][j]==0)
			{
				menor= matriz[i][j];
				temp=j;
			}
		}
		i=temp;
		caminho[cont+1]=i;
		soma_menor=soma_menor +menor;
		cont++;
	}

	cout<<"================================================================================================"<<endl;
	cout <<"Utilizando o Algoritmo do Vizinho mais proximo, o menor gasto é: $"<<soma_menor<<endl;
	cout <<"Sendo o melhor ciclo:";

	for(i=0;i<=size;i++)
		{
			caminho[i]=caminho[i]+1;
			cout <<" "<< caminho[i];
		}
	cout<<endl;
	cout<<"O valor do GAP de otimalidade é de: ";
	printf("%4.2f",gap(soma_menor));
	cout<<" %"<<endl;
	cout<<"================================================================================================"<<endl;
}




int main ( int argc, char *argv[ ])
{

	// Leitura do Arquivo
	char arquivo[100];
	int n, i;
	FILE* f;

	//printf ("\nIndique o arquivo para leitura: ");
	//scanf ("%s", &arquivo);

	//arquivo=argv[1];

	f = fopen (argv[1], "r");
	if (f==NULL)
		printf ("\nErro, nao foi possivel abrir o arquivo\n");
	fscanf (f, "%d", &n);

	Cidades cit[n];

	for (i=0; i<n; i++)
	{
		fscanf (f, "%d", &cit[i].cit);
		fscanf (f, "%f", &cit[i].x);
		fscanf (f, "%f", &cit[i].y);
	}

	fclose (f);

	menor.ciclo = new int[n];

	saida = argv[2];

	permute(cit, 1, n);

	solucao_otima (n);

	Vizinho_proximo (cit, n);

	delete []menor.ciclo;

}
