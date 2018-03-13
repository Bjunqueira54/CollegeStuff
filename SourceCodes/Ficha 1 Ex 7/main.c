/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: gothicdread
 *
 * Created on March 6, 2018, 2:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 3

void ex7()
{
    int mat[LINHAS][COLUNAS];
    int i, j, erro=0, conta=0;
    
    for(i=0;i<LINHAS;i++)
    {
        do
        {
            printf("%d. valor: ", i+1);
            scanf("%d", &mat[i][0]);
            erro = (mat[i][0] < 1 || mat[i][0] > 100);
            
            for(j=0; j<i && !erro; j++)
            {
                erro = (mat[i][0] == mat[j][0]);
            }
            
            if(erro)
                printf("Valor Invalido!\n");
        }
        while(erro);
        
        mat[i][1] = mat[i][0] * mat[i][0];
        mat[i][2] = mat[i][1] * mat[i][0];
    }
    
    for(i=0;i<LINHAS;i++)
    {
        for(j=0;j<COLUNAS;j++)
        {
            printf("%8d", mat[i][j]);
            if(mat[i][j]>1000)
            {
                conta++;
            }
        }
        putchar('\n');
    }
    
    printf("Conta: %d", conta);
}

int main(int argc, char** argv)
{
    ex7();
    return (EXIT_SUCCESS);
}

