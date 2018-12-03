#define _CRT_SECURE_NO_WARNINGS 1
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define GENERATIONS_TC  100
#define PROBGERAVIZ     1.0

// Calcula a qualidade de uma solucao
// Parametros de entrada: solucao (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parametros de saida: qualidade da solucao (se a capacidade for excedida devolve 0)
float eval_individual(int sol[], struct info d, int mat[][2], int *v)
{
	int     i;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso total
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
		}
	}
	if (sum_weight > d.capacity)
	{
        // Solucao invalida
		*v = 0;
		return 0;
	}
	else
	{
        // Solucao valida
		*v = 1;
		return sum_profit;
	}
}

// Calcula a qualidade de uma soluca com penalizacao
// Parametros de entrada: solucao (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parametros de saida: qualidade da solucao (se a capacidade for excedida devolve 0)
float eval_individual_penalizado(int sol[], struct info d, int mat[][2], int *v)
{
	int     i;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso total
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
            // Obtem o melhor ro
            if (d.ro < (float)mat[i][1]/mat[i][0])
                d.ro = (float)mat[i][1]/mat[i][0];
		}
	}
	if (sum_weight > d.capacity)
	{
        // Solucao invalida
		*v = 0;
		return sum_profit-(sum_weight-d.capacity)*d.ro; // Solucao com penalizacao
	}
	else
	{
        // Solucao valida
		*v = 1;
		return sum_profit;
	}
}

// Calcula a qualidade de uma solucao com reparacao aleatoria
// Parametros de entrada: solucao (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parametros de saida: qualidade da solucao (se a capacidade for excedida devolve 0)
float eval_individual_reparado1(int sol[], struct info d, int mat[][2], int *v)
{
	int     i;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso total
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
		}
	}
	// Processo de reparacao
    while (sum_weight > d.capacity)
    {
        // escolhe um objeto aleatoriamente
        i = random_l_h(0, d.numGenes-1);
        // Se esse objeto estiver na mochila, retira-o e ajusta os somatorios do peso e lucro
        if (sol[i] == 1)
        {
            sol[i] = 0;
            sum_weight -= mat[i][0];
            sum_profit -= mat[i][1];
        }
    }
    *v = 1;
	return sum_profit;
}

// Calcula a qualidade de uma solucao com reparacao de acordo com uma heuristica sofrega
// Parametros de entrada: solucao (sol), capacidade da mochila (d), matriz com dados do problema (mat) e numero de objectos (v)
// Parametros de saida: qualidade da solucao (se a capacidade for excedida devolve 0)
float eval_individual_reparado2(int sol[], struct info d, int mat[][2], int *v)
{
	int     i, mv, pos;
	float   sum_weight, sum_profit;

	sum_weight = sum_profit = 0;
	// Percorre todos os objectos
	for (i=0; i < d.numGenes; i++)
	{
        // Verifica se o objecto i esta na mochila
		if (sol[i] == 1)
		{
            // Actualiza o peso total
			sum_weight += mat[i][0];
            // Actualiza o lucro total
			sum_profit += mat[i][1];
		}
	}
	// Processo de reparacao 2
    while (sum_weight > d.capacity)
    {
        pos = -1;
        for (i=0; i < d.numGenes; i++)
        {
            if (sol[i] == 1)
            {
                if  (pos == -1 || mv > mat[i][1])
                {
                    mv = mat[i][1];
                    pos = i;
                }
            }
        }
        sol[pos] = 0;
        sum_weight -= mat[pos][0];
        sum_profit -= mat[pos][1];
    }
    *v = 1;
	return sum_profit;
}

// Avaliacao da populacao
// Parametros de entrada: populacao (pop), estrutura com parametros (d) e matriz com dados do problema (mat)
// Parametros de saida: Preenche pop com os valores de fitness e de validade para cada solucao
void evaluate(pchrom pop, struct info d, int mat[][2])
{
	int i;

	for (i=0; i<d.popsize; i++)
		pop[i].fitness = eval_individual(pop[i].p, d, mat, &pop[i].valido);
        // Exercicio 4.2(a)
//		pop[i].fitness = eval_individual_penalizado(pop[i].p, d, mat, &pop[i].valido);
        // Exercicio 4.2(b)
//		pop[i].fitness = eval_individual_reparado1(pop[i].p, d, mat, &pop[i].valido);
        // Exercicio 4.2(c)
//		pop[i].fitness = eval_individual_reparado2(pop[i].p, d, mat, &pop[i].valido);
}
