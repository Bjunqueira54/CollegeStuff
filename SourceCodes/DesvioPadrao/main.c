/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: gothicdread
 *
 * Created on March 6, 2018, 1:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float desvio_padrao(int n)
{
    int i, tab[n];
    float media, soma=0, dp;
    
    for(i=0;i<n;i++)
    {
        printf("%d valor: ", i+1);
        scanf("%i", &tab[i]);
        soma = soma + tab[i];
    }
    
    media = soma/n;
    
    soma = 0;
    for(i=0;i<n;i++)
    {
        soma += (media - tab[i]) * (media - tab[i]);
    }
    dp = sqrt(soma / n);
    
    return dp;
}

int main(int argc, char** argv)
{
    printf("Desvio Padrao: %.4f\n", desvio_padrao(4));
    return (EXIT_SUCCESS);
}

