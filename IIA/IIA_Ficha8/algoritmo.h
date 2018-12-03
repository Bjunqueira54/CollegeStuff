#define MAX_OBJ 1000		// Numero maximo de objectos

// EStrutura para armazenar parametros
struct info
{
    // Tamanho da populacao
    int     popsize;
    // Probabilidade de mutacao
    float   pm;
    // Probabilidade de recombinacao
    float   pr;
    // Tamanho do torneio para selecao do pai da proxima geracao
	int     tsize;
	// Constante para avaliacao com penalizacao
	float   ro;
	// Numero de objetos que se podem colocar na mochila
    int     numGenes;
	// Capacidade da mochila
	int     capacity;
	// Numero de geracoes
    int     numGenerations;
};

// Individuo (solucao)
typedef struct individual chrom, *pchrom;

struct individual
{
    // Solucao (objetos que estao dentro da mochila)
    int     p[MAX_OBJ];
    // Valor da qualidade da solucao
	float   fitness;
    // 1 se for uma solucao valida e 0 se nao for
	int     valido;
};

void tournament(pchrom, struct info, pchrom);

void tournament_geral(pchrom, struct info, pchrom);

void genetic_operators(pchrom, struct info, pchrom);

void crossover(pchrom, struct info, pchrom);

void mutation(pchrom, struct info);

void mutacao_por_troca(pchrom, struct info);
