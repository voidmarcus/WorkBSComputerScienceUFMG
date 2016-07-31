//Estrutura de dados utilizada para armazenar dados de uma imagem PGM.
typedef struct {
	int c; //número de colunas na imagem
	int l; //número de linhas na imagem
	unsigned char maximo; //valor máximo para cada pixel
	unsigned char **dados; //variável para armazenar os pixels da imagem (matriz)
} PGM;

// A estrutura de dados a seguir é utilizada para armazenar um ponto (x,y).
typedef struct {
	int x; //coluna
	int y; //linha
} Ponto;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: LePGM(char* entrada)
Função: Le os dados da imagem e armazena em uma estrutura de dados PGM.
Entrada: Arquivo no formato .PGM passada atraves dos argumentos argc e argv.
Saída: Estrutura contendo os dados da imagem.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
PGM *LePGM(char* entrada);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: CorrelacaoCruzada (PGM ∗ cena , PGM ∗ obj , Ponto p)
Função: Calcula a correlacao cruzada entre a duas imagens.
Entrada: Estruturas PGM contendo as matrizes da imagem e do objeto bem como oo ponto inicial.
Saída: Int resultado da correlação.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: JanelaDeslizante(PGM *cena, PGM *obj);
Função: 'Desliza' a matriz objeto atraves da matriz imagem.
Entrada: Estruturas PGM da imagem e do objeto.
Saída: Ponto onde o valor de correlação cruzada foi maior.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Ponto JanelaDeslizante(PGM *cena, PGM *obj);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: void LiberaPGM (PGM *imagem);
Função: Desaloca por completo toda uma estrutura PGM (inclusive a matriz de dados).
Entrada: Estrutura PGM.
Saída: "There is no life in the voild only death" Sauron.
 −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void LiberaPGM (PGM *imagem);
