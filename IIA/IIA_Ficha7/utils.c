#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Leitura do ficheiro de input
// Parametros de entrada: Nome do ficheiro, nome, Numero de vertices, n, Numero de iteracoes, iter
// Parametros de saida: Matriz de adjacencias, p
int* init_dados(char *nome, int *n, int *iter)
{
	FILE    *f;
	int     *p, *q;
	int     i, j;

	f=fopen(nome, "rt");
	if (!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	// Le o numero de iteracoes
	fscanf(f, " %d", iter);
	// Le o numero de vertices
	fscanf(f, " %d", n);
	// Aloca espaco em memoria para guardar a matriz de adjacencias
	p = malloc(sizeof(int)*(*n)*(*n));
	if (!p)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	q = p;
	// Preenchimento da matriz de adjacencias
	for (i = 0; i < *n; i++)
        for (j=0; j < *n; j++)
            fscanf(f, " %d", q++);
	fclose(f);
	// Devolve a matriz de adjacencias
	return p;
}

// Gera a solucao inicial
// Par�metros de entrada: Solucao, sol, Numero de vertices, v
void gera_sol_inicial(int *sol, int v)
{
	int i, x;

	for (i = 0; i < v; i++)
        sol[i] = 0;
	for (i = 0; i < v/2; i++)
    {
        do
			x = random_l_h(0, v-1);
        while (sol[x] != 0);
        sol[x] = 1;
    }
}

// Escreve solucao no ecra
// Parametros de entrada: Solucao, sol, Numero de vertices, vert
void escreve_sol(int *sol, int vert)
{
	int i;

	printf("\nConjunto A: ");
	for (i = 0; i < vert; i++)
		if(sol[i] == 0)
			printf("%2d  ", i);
	printf("\nConjunto B: ");
	for (i = 0; i < vert; i++)
		if (sol[i] == 1)
			printf("%2d  ", i);
	printf("\n");
}

// copia vector b para a (tamanho n)
// Parametros de entrada: Solucao que sera substituida, a, Solucao que ira substituir, b, Numero de vertices, n
void substitui(int a[], int b[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = b[i];
}

// Inicializa o gerador de numeros aleatorios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Gera um valor inteiro aleatorio entre min e max
// Parametros de entrada: Valor inferior do intervalo, min, Valor superior do intervalo, max
// Parametros de saida: Valor aleatorio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max - min + 1);
}

// Gera um valor inteiro aleatorio entre 0 e 1
// Parametros de saida: Valor aleatorio entre 0 e 1
float rand_01()
{
	return ((float)rand()) / RAND_MAX;
}
