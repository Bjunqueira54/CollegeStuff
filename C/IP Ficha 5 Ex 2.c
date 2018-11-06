#include <stdio.h>

int limites(float min, float max, float n)
{
    if(n>min && n<max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    float min, max, n;

    printf("Introduza o Limite minimo: ");
    scanf("%f", &min);

    printf("Introduza o Limite maximo: ");
    scanf("%f", &max);

    printf("Introduza o numero a verificar: ");
    scanf("%f", &n);

    if(limites(min, max, n)==1)
    {
        printf("O numero esta contido dentro do limite");
    }
    else if(limites(min, max, n) != 1)
    {
        printf("O numero nao esta contido no limite");
    }
}
