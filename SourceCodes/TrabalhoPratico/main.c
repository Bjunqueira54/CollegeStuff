/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "functions.h"

void _MenuGuitarra();
void _MenuClientes();
void _MenuAluguer();

void _MenuPrincipal()
{
    int escolha;
    
    system("cls");
    
    printf("Bem-vindo a Guitarras p'Aluger\n");
    printf("\t1- Guitarras\n");
    printf("\t2- Clientes\n");
    printf("\t3- Aluger\n");
    printf("\t4- Fechar Programa\n\n");
    
    printf("Escolha: ");
    fscanf(stdin, "%i", &escolha);
    
    switch(escolha)
    {
        case 1:
            _MenuGuitarra();
            break;
        case 2:
            _MenuClientes();
            break;
        case 3:
            _MenuAluguer();
            break;
        case 4:
            return;
            break;
        default:
            system("cls");
            printf("Escolha Invalida!");
            fflush(stdin);
            getchar();
            _MenuPrincipal();
            break;
    }
}

void _MenuGuitarra()
{
    system("cls");
    printf("Menu de Guitarras\n");
    printf("\t1- Adicionar guitarra ao stock\n");
    printf("\t2- Mostrar historico de alugueres\n");
    printf("\t3- Listar todas as guitarras\n");
    printf("\t4- Listar guitarras alugadas\n");
    printf("\t5- Menu anterior...\n\n");
    
    int escolha;
    
    printf("Escolha: ");
    fscanf(stdin, "%i", &escolha);
    
    switch(escolha)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            _MenuPrincipal();
            break;
        default:
            system("cls");
            printf("Escolha Invalida!");
            fflush(stdin);
            getchar();
            _MenuGuitarra();
            break;
    }
}

void _MenuClientes()
{
    system("cls");
    printf("Menu de Clientes\n");
    printf("\t1- Novo Cliente\n");
    printf("\t2- Remover Cliente\n");
    printf("\t3- Mostrar Cliente\n");
    printf("\t4- Listar todos os clientes ativos\n");
    printf("\t5- Listar todos os clientes banidos\n");
    printf("\t6- Menu anterior...\n");
    printf("\tBanir Clientes (Passivamente)\n\n");

    
    int escolha;
    
    printf("Escolha: ");
    fscanf(stdin, "%i", &escolha);
    
    switch(escolha)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            _MenuPrincipal();
            break;
        default:
            system("cls");
            printf("Escolha Invalida!");
            fflush(stdin);
            getchar();
            _MenuClientes();
            break;
    }
}

void _MenuAluguer()
{
    system("cls");
    int escolha;
    
    printf("Menu de Aluguer\n");
    printf("\t1- Novo Aluguer\n");
    printf("\t2- Concluir Aluguer\n");
    printf("\t3- Listar Alugueres\n");
    printf("\t4- Menu anterior...\n\n");
    
    printf("Escolha: ");
    fscanf(stdin, "%i", &escolha);
    
    switch(escolha)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            _MenuPrincipal();
            break;
        default:
            system("cls");
            printf("Escolha Invalida!");
            fflush(stdin);
            getchar();
            _MenuAluguer();
            break;
    }
}

int main(int argc, char** argv)
{
    _MenuPrincipal();
    return (EXIT_SUCCESS);
}

