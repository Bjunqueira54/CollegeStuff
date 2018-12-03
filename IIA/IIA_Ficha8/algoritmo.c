#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "utils.h"

// Preenche uma estrutura com os progenitores da proxima geracao, de acordo com o resultados do torneio binario (tamanho de torneio: 2)
// Parametros de entrada: populacao actual (pop), estrutura com parametros (d) e populacao de pais a encher
void tournament(pchrom pop, struct info d, pchrom parents)
{
	int i, x1, x2;

	// Realiza popsize torneios
	for (i=0; i<d.popsize;i++)
	{
		x1 = random_l_h(0, d.popsize-1);
		do
			x2 = random_l_h(0, d.popsize-1);
		while (x1==x2);
		if (pop[x1].fitness > pop[x2].fitness)		// Problema de maximizacao
			parents[i] = pop[x1];
		else
			parents[i] = pop[x2];
	}
}

// Preenche uma estrutura com os progenitores da proxima geracao, de acordo com o resultados do torneio binario (tamanho de torneio: 2)
// Parametros de entrada: populacao actual (pop), estrutura com parametros (d) e populacao de pais a encher
void tournament_geral(pchrom pop, struct info d, pchrom parents)
{
	int i, j, k, sair, best, *pos;

	pos = malloc(d.tsize*sizeof(int));
	// Realiza popsize torneios
	for(i=0; i<d.popsize;i++)
	{
	    // Seleciona tsize solucoes diferentes para entrarem em torneio de selecao
		for(j=0; j<d.tsize; j++)
        {
            do
            {
                pos[j] = random_l_h(0, d.popsize-1);
                // Verifica se a nova posicao escolhida e igual a alguma das outras posicoes escolhidas
                sair = 0;
                for (k=0; k<j; k++)
                {
                    if (pos[k]==pos[j])
                        sair = 1;
                }
            }
            while (sair);
            // Guarda a posicao da melhor solucao de todas as que entraram em torneio
            if (j==0 || pop[pos[j]].fitness > pop[pos[best]].fitness)		// Problema de maximizacao
                best = j;
        }
        parents[i] = pop[pos[best]];
	}
	free(pos);
}

// Operadores geneticos a usar na geracao dos filhos
// Parametros de entrada: estrutura com os pais (parents), estrutura com parametros (d), estrutura que guarda os descendentes (offspring)
void genetic_operators(pchrom parents, struct info d, pchrom offspring)
{
    // Recombinacao com um ponto de corte
	crossover(parents, d, offspring);
	// Recombinacao com dois pontos de corte
    // Exercicio 4.4(a)
//	recombinacao_dois_pontos_corte(parents, d, offspring);
	// Recombinacao uniforme
    // Exercicio 4.4(b)
//	recombinacao_uniforme(parents, d, offspring);
	// Mutacao binaria
	mutation(offspring, d);
    // Mutacao por troca
    // Exercicio 4.3
//	mutacao_por_troca(offspring, d);
}

// Preenche o vector descendentes com o resultado da operacao de recombinacao com um ponto de corte
// Parametros de entrada: estrutura com os pais (parents), estrutura com parametros (d), estrutura que guarda os descendentes (offspring)
void crossover(pchrom parents, struct info d, pchrom offspring)
{
	int i, j, point;

	for (i=0; i<d.popsize; i+=2)
	{
		if (rand_01() < d.pr)
		{
			point = random_l_h(0, d.numGenes-1);
			for (j=0; j<point; j++)
			{
				offspring[i].p[j] = parents[i].p[j];
				offspring[i+1].p[j] = parents[i+1].p[j];
			}
			for (j=point; j<d.numGenes; j++)
			{
				offspring[i].p[j]= parents[i+1].p[j];
				offspring[i+1].p[j] = parents[i].p[j];
			}
		}
		else
		{
			offspring[i] = parents[i];
			offspring[i+1] = parents[i+1];
		}
	}
}

// Preenche o vector descendentes com o resultado da operacao de recombinacao com dois pontos de corte
// Parametros de entrada: estrutura com os pais (parents), estrutura com parametros (d), estrutura que guarda os descendentes (offspring)
void recombinacao_dois_pontos_corte(pchrom parents, struct info d, pchrom offspring)
{
	int i, j, point1, point2;

	for (i=0; i<d.popsize; i+=2)
	{
		if (rand_01() < d.pr)
		{
			point1 = random_l_h(0, d.numGenes-2);
			point2 = random_l_h(point1+1, d.numGenes-1);
			for (j=0; j<point1; j++)
			{
				offspring[i].p[j] = parents[i].p[j];
				offspring[i+1].p[j] = parents[i+1].p[j];
			}
			for (j=point1; j<point2; j++)
			{
				offspring[i].p[j]= parents[i+1].p[j];
				offspring[i+1].p[j] = parents[i].p[j];
			}
			for (j=point2; j<d.numGenes; j++)
			{
				offspring[i].p[j] = parents[i].p[j];
				offspring[i+1].p[j] = parents[i+1].p[j];
			}
		}
		else
		{
			offspring[i] = parents[i];
			offspring[i+1] = parents[i+1];
		}
	}
}

// Preenche o vector descendentes com o resultado da operacao de recombinacao uniforme
// Parametros de entrada: estrutura com os pais (parents), estrutura com parametros (d), estrutura que guarda os descendentes (offspring)
void recombinacao_uniforme(pchrom parents, struct info d, pchrom offspring)
{
	int i, j;

	for(i=0; i<d.popsize; i+=2)
	{
		if(rand_01() < d.pr)
		{
			for(j=0; j<d.numGenes; j++)
			{
                if (flip() == 1)
                {
                    offspring[i].p[j] = parents[i].p[j];
                    offspring[i+1].p[j] = parents[i+1].p[j];
                }
                else
                {
                    offspring[i].p[j] = parents[i+1].p[j];
                    offspring[i+1].p[j] = parents[i].p[j];
                }
			}
		}
		else
		{
			offspring[i] = parents[i];
			offspring[i+1] = parents[i+1];
		}
	}
}

// Mutacao binaria com varios pontos de mutacao
// Parametros de entrada: estrutura com os descendentes (offspring) e estrutura com parametros (d)
void mutation(pchrom offspring, struct info d)
{
	int i, j;

	for (i=0; i<d.popsize; i++)
		for (j=0; j<d.numGenes; j++)
			if (rand_01() < d.pm)
				offspring[i].p[j] = !(offspring[i].p[j]);
}

// Mutacao por troca
// Parametros de entrada: estrutura com os descendentes (offspring) e estrutura com parametros (d)
void mutacao_por_troca(pchrom offspring, struct info d)
{
	int i, pos1, pos2, aux;

	for (i=0; i<d.popsize; i++)
        if (rand_01() < d.pm)
        {
            do
                pos1 = random_l_h(0, d.numGenes-1);
            while (offspring[i].p[pos1] == 1);
            do
                pos2 = random_l_h(0, d.numGenes-1);
            while (offspring[i].p[pos2] == 0);
            aux = offspring[i].p[pos1];
            offspring[i].p[pos1] = offspring[i].p[pos2];
            offspring[i].p[pos2] = aux;
        }
}
