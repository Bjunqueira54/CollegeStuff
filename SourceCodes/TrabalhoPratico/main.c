/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define NAME 101

#define CLTTXT "clientes.txt"
#define GTRTXT "guitarras.txt"
#define BAN "listanegra.bin"

pClientes c = NULL;
Guitarras *g_vec = NULL;

int g_tam = 0;

void MenuGuitarra()
{
    int escolha/* = 1*/;
    
    while(escolha != 0)
    {
        printf("Menu de Guitarras\n");
        printf("\t1- Adicionar guitarra ao stock\n");
        printf("\t2- Mostrar historico de alugueres\n");
        printf("\t3- Listar todas as guitarras\n");
        printf("\t4- Listar guitarras alugadas\n");
        printf("\t0- Menu anterior...\n\n");
            
        printf("Escolha: ");
        fscanf(stdin, "%i", &escolha);
        
        switch(escolha)
        {
            case 1:
                g_vec = AdicionarGuitarras(g_vec, &g_tam);
                break;
            case 2:
                break;
            case 3:
                ListaGuitarras(g_vec, g_tam);
                break;
            case 4:
                break;
            case 0:
                break;
            default:
                printf("Escolha Invalida!\n");
                break;
        }
    }
}

void MenuClientes()
{
    int escolha/* = 1*/;

    while(escolha != 0)
    {
        printf("Menu de Clientes\n");
        printf("\t1- Novo Cliente\n");
        printf("\t2- Remover Cliente\n");
        printf("\t3- Mostrar Cliente\n");
        printf("\t4- Listar todos os clientes ativos\n");
        printf("\t5- Listar todos os clientes banidos\n");
        printf("\t0- Menu anterior...\n");
        printf("\tBanir Clientes (Passivamente)\n\n");

        printf("Escolha: ");
        fscanf(stdin, "%i", &escolha);
    
        switch(escolha)
        {
            case 1:
                c = AdicionarCliente(c);
                break;
            case 2:
                c = RemoverCliente(c);
                break;
            case 3:
                break;
            case 4:
                ListaClientesAtivos(c);
                break;
            case 5:
                break;
            case 0:
                break;
            default:
                printf("Escolha Invalida!\n");
                break;
        }
    }
}

void MenuAluguer()
{
    int escolha/* = 1*/;
    
    while(escolha != 0)
    {
        printf("Menu de Aluguer\n");
        printf("\t1- Novo Aluguer\n");
        printf("\t2- Concluir Aluguer\n");
        printf("\t3- Listar Alugueres\n");
        printf("\t0- Menu anterior...\n\n");
    
        printf("Escolha: ");
        fscanf(stdin, "%i", &escolha);
        
        switch(escolha)
        {
            case 1:
                c = NovoAluguer(c, g_vec, g_tam);
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                break;
            default:
                printf("Escolha Invalida!\n");
                break;
        }
    }
}

int main(int argc, char** argv)
{
    int escolha;
    
    g_vec = LeFicheiroGuitarras(GTRTXT, &g_tam);    //Chama a função de leitura do ficheiro das Guitarras e escreve para o vetor
    c = LeFicheiroClientes(CLTTXT);                 //Chama a função de leitura do ficheiro de Clientes e escreve para a lista ligada
    //h = LeFicheiroHistorico(CLTTXT);
    while(escolha != 0) //Enquanto a escolha nao for 0, o ciclo repete-se
    {
        printf("Bem-vindo a Guitarras p'Aluguer\n");
        printf("\t1- Guitarras\n");
        printf("\t2- Clientes\n");
        printf("\t3- Aluger\n");
        printf("\t0- Sair\n\n");
        
        printf("Escolha: ");
        fscanf(stdin, "%i", &escolha);
        
        switch(escolha)
        {
            case 1:
                MenuGuitarra();
                break;
            case 2:
                MenuClientes();
                break;
            case 3:
                MenuAluguer();
                break;
            case 0:
                if(c != NULL)   //se o ponteiro do inicio da lista estiver vazio (NULL)
                {               //entao saltará o processo de guardar
                    GuardaDadosClientes(CLTTXT, c);
                }
                if(g_vec != NULL)   //Exatamente igual para o vetor das guitarras
                {
                    GuardaDadosGuitarras(GTRTXT, g_vec, g_tam);
                }
                break;
            default:    //Handle básico de qualquer escolha numérica fora do alcance de 1<->3 e 0
                fprintf(stderr, "Escolha Invalida!");
        }
    }
    return (EXIT_SUCCESS);
}

