#include <stdio.h>

void main()
{
    float n, nMax, soma, media;
    int nSize;

    nMax = -1000000;
    n = -100000;
    soma = 0;
    nSize = 0;

    while(n >= nMax)
    {
        nMax = n;

        printf("Introduza um numero: ");
        scanf("%f", &n);

        if(n>nMax)
        {
            soma = soma + n;
            nSize = nSize+1;
        }
        else
            printf("\n");

    }

    media = soma/nSize;

    printf("A soma de todos os numeros e %f e a media deles e %f", soma, media);
}
