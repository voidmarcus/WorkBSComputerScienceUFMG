// Armazena as coordenadas do ponto
typedef struct{
        float x,y,z;
} Coordenadas;


// Estrutura utilizada para armazenar os átomos da proteina
typedef struct{
        Coordenadas posicao;
} OctreeCoordenadas;


// Estrutura da octree
typedef struct _Node{
        Coordenadas origem;       // Ponto central do cubo
        Coordenadas meiaDimensao;        // Metade das dimensoes do cubo

        Coordenadas verticeMin;         // Menor vertice do cubo (menores valores de x,y e z
        Coordenadas verticeMax;         // Maior vertice do cubo (maiores valores de x,y e z

        Coordenadas *data;           // Se for uma folha este será utilizado para armazenar um átomo da proteina
        struct _Node *filhos[8];   // Se for um nodo interno, este vetor aponta para seus filhos
} Octree;


typedef struct {
		char nome[5];
		int interacoes;
}Ligante;


// Estrutura de um cubo
typedef struct _cubo{
        Coordenadas origem;       // Ponto central do cubo
        int meiaDimensao;        // Metade das dimensoes do cubo

        Coordenadas verticeMin;         // Menor vertice do cubo (menores valores de x,y e z
        Coordenadas verticeMax;         // Maior vertice do cubo (maiores valores de x,y e z
} Cubo;




bool ehInterno(Octree *no);

void imprimiOctree (Octree *octree);

int qualOctante (Octree *octree, Coordenadas *coordenada);

Octree* alocaOctree(Coordenadas *maiorVertice, Coordenadas *menorVertice);

void insere (Octree *no, Coordenadas *pontos);

void pontosDentroCubo (Coordenadas *verticeMin, Coordenadas *verticeMax, Octree *octree,int *contador);




/*
child:					0 1 2 3 4 5 6 7
				x:      - - - - + + + +
				y:      - - + + - - + +
				z:      - + - + - + - +
*/
