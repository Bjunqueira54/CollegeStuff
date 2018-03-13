#include <stdio.h>

void funcao(int numero)
{
    printf("%i", numero);
}

void main()
{
    int seila;

    printf("Introduza um numero: ");
    scanf("%i", &seila);
    funcao(seila);
}
