/*
 Nome do Aluno: Bruno Miguel Almeida Junqueira
 Nº do Aluno: 21270345
 Turma Prática: P3
 */

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main(int argc, char** argv)
{
    int escolha;
    
    while(escolha != 0)
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
                break;
            default:
                printf("Escolha Invalida!");
        }
    }
    return (EXIT_SUCCESS);
}

