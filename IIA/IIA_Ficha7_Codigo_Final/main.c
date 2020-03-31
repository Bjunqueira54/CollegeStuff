#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "utils.h"

#define DEFAULT_RUNS 10

int main(int argc, char *argv[])
{
    char    nome_fich[100];
    int     vert, num_iter, k, runs, custo, best_custo;
    int     *grafo, *sol, *best;
    float   mbf = 0.0;

    // Le os argumentos de entrada
    if (argc == 3)
    {
        runs = atoi(argv[2]);
        //strcpy(nome_fich, argv[1]);
        strncpy(nome_fich, argv[1], 99);
    }
    else
    // Se o numero de execucoes do processo nao for colocado nos argumentos de entrada, define-o com um valor por defeito
    if (argc == 2)
    {
        runs = DEFAULT_RUNS;
        //strcpy(nome_fich, argv[1]);
        strncpy(nome_fich, argv[1], 99);
    }
    // Se o nome do ficheiro de informacoes nao for colocado nos argumentos de entrada, pede-o novamente
    else
    {
        runs = DEFAULT_RUNS;
        printf("Nome do Ficheiro: ");
        fgets(nome_fich, 99, stdin);
        nome_fich[strlen(nome_fich) - 1] = '\0';
    }
    // Se o numero de execucoes do processo for menor ou igual a 0, termina o programa
    if (runs <= 0)
        return 0;
        
    //Inicializa a geracao dos numeros aleatorios
    init_rand();
    
    // Preenche matriz de adjacencias, o numero de vertices a usar e o numero de iteracoes a fazer com o trepa colinas
    grafo = init_dados(nome_fich, &vert, &num_iter);
    
    // Aloca espaco em memoria para guardar uma solucao
    sol = malloc(sizeof(int) * vert);
    
    // Aloca espaco em memoria para guardar a melhor solucao
    best = malloc(sizeof(int) * vert);
    
    // Caso nao consiga fazer as alocacoes, envia aviso e termina o programa
    if(sol == NULL || best == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    // Faz um ciclo com o numero de execucoes definidas
    for(k=0; k<runs; k++)
    {
        // Gera a solucao inicial
        gera_sol_inicial(sol, vert);
        
        // Mostra a solucao inicial
        escreve_sol(sol, vert);
        
        // Executa o algoritmo do trepa colinas
        custo = trepa_colinas(sol, grafo, vert, num_iter);
        
        // Ficha 7 - 4.4
        //custo = trepa_colinas_probabilistico(sol, grafo, vert, num_iter);
        
        //Ficha 7 - 4.5
        //custo = recristalizacao_simulada(sol, grafo, vert, num_iter);
        
        // Mostra a solucao encontrada na repeticao k e o seu custo
        printf("\nRepeticao %d:", k);
        escreve_sol(sol, vert);
        printf("Custo final: %2d\n", custo);
        
        // Acumula o custo das solucoes encontradas
        mbf += custo;
        
        // Guarda a melhor solucao encontrada
        if(k==0 || best_custo > custo)
        {
            best_custo = custo;
            substitui(best, sol, vert);
        }
    }
        
    // Calcula e mostra a media dos custos de todas as melhores solucoes encontradas
    printf("\n\nMBF: %f\n", mbf/k);
    
    // Mostra a melhor solucao encontrada e o seu respectivo custo
    printf("\nMelhor solucao encontrada");
    escreve_sol(best, vert);
    printf("Custo final: %2d\n", best_custo);
    
    // Liberta a memoria usada
    free(grafo);
    free(sol);
    free(best);
    
    return 0;
}
