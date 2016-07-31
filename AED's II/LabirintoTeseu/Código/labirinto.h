typedef struct {
	int N; // Dimensão do labirinto, lmebre-se que o mesmo é N x N
	int x; // Coordenada x da entrada
	int y; // Coordenada y da entrada
	int sx; // Coordenada x da espada
	int sy; // Coordenada y da espada
	unsigned char **mapa; // variável para armazenar o mapa (matriz)
}Labirinto;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: Labirinto *LeLabirinto(char *entrada)
Função: Le os dados da imagem e armazena em uma estrutura de dados Labirinto.
Entrada: Arquivo txt, conforme especificacao passada atraves dos argumentos argc e argv.
Saída: Estrutura Labirinto contendo os dados da entrada.
ATENCAO: E' necessario utilizar a funcao LiberaLabirinto no final do programa para que seja
liberada a memoria alocada nessa funcao.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
Labirinto *LeLabirinto(char *entrada);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: void LiberaLabirinto(Labirinto *lab);
Função: Desaloca por completo toda uma estrutura Labirinto (inclusive a matriz mapa).
Entrada: Estrutura Labirinto.
Saída: "There is no life in the voild only death" Sauron.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void LiberaLabirinto(Labirinto *lab);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y, int ** sol)
Função: Computa recursivamente o caminho entre a entrada do labirinto até o local em que a es
pada se encontra.
Entrada: Labirinto, coordenadas iniciais x e y, ponteiro para matriz solucao (sol)
Saída: Retorna 0 caso nao encontre caminho e 1 caso encontre. | Matriz sol guarda o caminho c
orreto ou fica zerada caso nao haja caminho valido.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y, int ** sol);

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Protótipo: CaminhaLabirintoIterativo(Labirinto* lab, int x, int y, int ** sol)
Função: Computa interativamente utilizando pilhas o caminho entre a entrada do labirinto até
o local em que a espada se encontra. (Busca de Profundidade)
Entrada: Labirinto, coordenadas iniciais x e y, ponteiro para matriz solucao (sol)
Saída: Retorna 0 caso nao encontre caminho e 1 caso encontre. | Matriz sol guarda o caminho c
orreto ou fica zerada caso nao haja caminho valido.
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int CaminhaLabirintoIterativo(Labirinto* lab, int x, int y, int ** sol);

