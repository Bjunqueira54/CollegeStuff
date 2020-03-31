#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define PROB 0.01 // probabilidade fixa do algoritmo do trepa-colinas probabil�stico
#define TMAX 100
#define TMIN 5

// Gera um vizinho a distancia 1 (troca um vertice de cada grupo)
// Parametros de entrada: Solucao actual a, Solucao vizinha b, Numero de vertices n
void gera_vizinho(int a[], int b[], int n)
{
    int i, p1, p2;

    // Copia a solucao atual para a solucao vizinha
    for(i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    
    // Encontra aleatoriamente a posicao de um vertice com valor 0
    do
        p1 = random_l_h(0, n-1);
    while(b[p1] != 0);
    
    // Encontra aleatoriamente a posicao de um vertice com valor 1
    do
        p2 = random_l_h(0, n-1);
    while(b[p2] != 1);
    
    // Troca os valores dos vertices das posicoes encontradas
    b[p1] = 1;
    b[p2] = 0;
}

// Gera um vizinho a distancia 2 (troca dois vertices de cada grupo)
// Parametros de entrada: Solucao actual a, Solucao vizinha b, Numero de vertices n
void gera_vizinho2(int a[], int b[], int n)
{
    int i, p1, p2, p3, p4;

    // Copia a solucao atual para a solucao vizinha
    for(i = 0; i < n; i++)
        b[i] = a[i];
    
    // Encontra aleatoriamente a posicao de um vertice com valor 0
    do
        p1 = random_l_h(0, n-1);
    while(b[p1] != 0);
    
    // Encontra aleatoriamente a posicao de um vertice com valor 1
    do
        p2 = random_l_h(0, n-1);
    while(b[p2] != 1);
    
    // Troca os valores dos vertices das posicoes encontradas
    b[p1] = 1;
    b[p2] = 0;
    
    // Encontra aleatoriamente a posicao de um vertice, que nao seja igual a p2, com valor 0
    do
        p3 = random_l_h(0, n-1);
    while(b[p3] != 0 || p3 == p2);
    
    // Encontra aleatoriamente a posicao de um vertice, que nao seja igual a p1, com valor 1
    do
        p4 = random_l_h(0, n-1);
    while(b[p4] != 1 || p4 == p1);
    
    // Troca os valores dos vertices das posicoes encontradas
    b[p3] = 1;
    b[p4] = 0;
}

// Trepa colinas first-choice
// Parametros de entrada: Solucao sol, Matriz de adjacencias mat, Numero de vertices vert, Numero de iteracoes num_iter
// Parametros de saida: Custo da melhor solucao encontrada
int trepa_colinas(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i;

    // Aloca espaco em memoria para guardar a nova solucao
    nova_sol = malloc(sizeof(int)*vert);
    
    // Caso nao consiga fazer a alocacao, envia aviso e termina o programa
    if (nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    // Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);
    
    for(i = 0; i < num_iter; i++)
    {
        // Gera solucao vizinha
        gera_vizinho(sol, nova_sol, vert);
        
        // Ficha 7 - 4.3
        //gera_vizinho2(sol, nova_sol, vert);
        
        // Avalia solucao vizinha
        custo_viz = calcula_fit(nova_sol, mat, vert);
        
        // Fica com a solucao vizinha se o custo diminuir (problema de minimizacao) em relacao a solucao atual
        if (custo_viz < custo)
        // Ficha 7 - 4.2
        //if (custo_viz <= custo)
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }
    }
    
    // Liberta a memoria usada para guardar a nova solucao
    free(nova_sol);
    
    // Devolve o custo da melhor solucao encontrada
    return custo;
}

// Trepa colinas first-choice
// Parametros de entrada: Solucao, sol, Matriz de adjacencias, mat, Numero de vertices, vert, Numero de iteracoes, num_iter
// Parametros de saida: Custo da melhor solucao encontrada
int trepa_colinas_probabilistico(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i;

    // Aloca espaco em memoria para guardar a nova solucao
    nova_sol = malloc(sizeof(int)*vert);
    
    // Caso nao consiga fazer a alocacao, envia aviso e termina o programa
    if (nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    // Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);
    
    for(i = 0; i < num_iter; i++)
    {
        // Gera solucao vizinha
        gera_vizinho(sol, nova_sol, vert);
        
        // Avalia solucao vizinha
        custo_viz = calcula_fit(nova_sol, mat, vert);
        
        // Fica com a solucao vizinha se o custo diminuir (problema de minimizacao) em relacao a solucao atual
        if (custo_viz <= custo)
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }
        else
        {
            // Fica com a solu��o vizinha, apesar de pior, se o valor aleat�rio gerado for abaixo da probabilidade definida
            if (rand_01() < PROB)
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
    }
    
    // Liberta a mem�ria usada para guardar a nova solu��o
    free(nova_sol);
    
    // Devolve o custo da melhor solu��o encontrada
    return custo;
}

int recristalizacao_simulada(int sol[], int *mat, int vert, int num_iter)
{
    int     *nova_sol, custo, custo_viz, i, best_custo, *best_sol;
    float   t = TMAX, decrementoT;

    // Calculo da decrementa��o de T para ir de TMAX a TMIN en num_iter
    decrementoT = (TMAX - TMIN) / num_iter;
    
    // Aloca espa�o em mem�ria para guardar a nova solu��o e a melhor solu��o
    nova_sol = malloc(sizeof(int)*vert);
    best_sol = malloc(sizeof(int)*vert);
    
    // Caso n�o consiga fazer a aloca��o, envia aviso e termina o programa
    if(nova_sol == NULL || best_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    
    // Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);
    
    // Guarda essa solu��o inicial como a melhor
    best_custo = custo;
    substitui(best_sol, sol, vert);
    
    for(i=0; i < num_iter; i++)
    {
        // Gera solu��o vizinha
        gera_vizinho(sol, nova_sol, vert);
        
        // Avalia solu��o vizinha
        custo_viz = calcula_fit(nova_sol, mat, vert);
        
        // Se a solu��o vizinha for melhor que a solu��o atual, guarda-a como a melhor solu��o
        if(custo_viz < best_custo)
        {
            best_custo = custo_viz;
            substitui(best_sol, nova_sol, vert);
        }
        
        // Fica com a solu��o vizinha se o custo n�o aumentar (problema de minimiza��o) em rela��o � solu��o atual
        if(custo_viz <= custo)
        {
            substitui(sol, nova_sol, vert);
            custo = custo_viz;
        }
        else
        {
            // Fica com a solu��o vizinha, apesar de pior, se o valor aleat�rio gerado for abaixo da probabilidade que se vai ajustando
            if (rand_01() < exp((custo - custo_viz) / t))
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
        
        t = t - decrementoT;
    }
    
    // Retorna a melhor solu��o encontrada
    substitui(sol, best_sol, vert);
    
    // Liberta a mem�ria usada para guardar a nova solu��o e a melhor solu��o
    free(nova_sol);
    free(best_sol);
    
    // Devolve o custo da melhor solu��o encontrada
    return best_custo;
}
