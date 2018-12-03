#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define DEFAULT_RUNS	10

int main(int argc, char *argv[])
{
	char        nome_fich[100];
	struct info EA_param;
	pchrom      pop = NULL, parents = NULL;
	chrom       best_run, best_ever;
	int         gen_actual, r, runs, i, inv, mat[MAX_OBJ][2];
	float       mbf = 0.0;

    // Le os argumentos de entrada
	if (argc == 3)
	{
		runs = atoi(argv[2]);
		strcpy(nome_fich, argv[1]);
	}
	else
        // Se o numero de execucoes do processo nao for colocado nos argumentos de entrada, define-o com um valor por defeito
        if (argc == 2)
        {
            runs = DEFAULT_RUNS;
            strcpy(nome_fich, argv[1]);
        }
        // Se o nome do ficheiro de informacoes nao for colocado nos argumentos de entrada, pede-o novamente
        else
        {
            runs = DEFAULT_RUNS;
            printf("Nome do Ficheiro: ");
            fgets(nome_fich, 99, stdin);
        }
    // Se o numero de execucoes do processo for menor ou igual a 0, termina o programa
	if (runs <= 0)
		return 0;
    //Inicializa a geracao dos numeros aleatorios
	init_rand();
    // Preenche a matriz com dados dos objectos (peso e valor) e a estrutura EA_param que foram definidos no ficheiro de input
	EA_param = init_data(nome_fich, mat);
	// Faz um ciclo com o numero de execucoes definidas
	for (r=0; r<runs; r++)
	{
		printf("Repeticao %d\n",r+1);
        // Geracao da populacao inicial
		pop = init_pop(EA_param);
        // Avalia a populacao inicial
		evaluate(pop, EA_param, mat);
		// Como ainda nao existe, escolhe-se como melhor solucao a primeira da populacao (poderia ser outra qualquer)
		best_run = pop[0];
        // Encontra-se a melhor solucao dentro de toda a populacao
		best_run = get_best(pop, EA_param, best_run);
        // Reserva espaco para os pais da populacao seguinte
		parents = malloc(sizeof(chrom)*EA_param.popsize);
        // Caso nao consiga fazer a alocacao, envia aviso e termina o programa
		if (parents==NULL)
		{
			printf("Erro na alocacao de memoria\n");
			exit(1);
		}
		// Ciclo de optimizacao
		gen_actual = 1;
		while (gen_actual <= EA_param.numGenerations)
		{
            // Torneio binario para encontrar os progenitores (ficam armazenados no vector parents)
			tournament(pop, EA_param, parents);
            // Torneio de k elementos, com k >= 2, para encontrar os progenitores (ficam armazenados no vector parents)
            // Exercicio 4.5
//            tournament_geral(pop, EA_param, parents);
            // Aplica os operadores geneticos aos pais (os descendentes ficam armazenados na estrutura pop)
			genetic_operators(parents, EA_param, pop);
            // Avalia a nova populacao (a dos filhos)
			evaluate(pop, EA_param, mat);
            // Actualiza a melhor solucao encontrada
			best_run = get_best(pop, EA_param, best_run);
			gen_actual++;
		}
		// Contagem das solucoes invalidas
		for (inv=0, i=0; i<EA_param.popsize; i++)
			if (pop[i].valido == 0)
				inv++;
		// Escreve resultados da repeticao que terminou
		printf("\nRepeticao %d:", r);
		write_best(best_run, EA_param);
		printf("\nPercentagem Invalidos: %f\n", 100*(float)inv/EA_param.popsize);
		mbf += best_run.fitness;
		if (r==0 || best_run.fitness > best_ever.fitness)
			best_ever = best_run;
        // Liberta a memoria usada
		free(parents);
		free(pop);
	}
	// Escreve resultados globais
	printf("\n\nMBF: %f\n", mbf/r);
	printf("\nMelhor solucao encontrada");
	write_best(best_ever, EA_param);
	return 0;
}
