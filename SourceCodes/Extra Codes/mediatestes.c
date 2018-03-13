#include <stdio.h>

void main()
{
    int i;
    float teste, media, soma;

    for(i=1, soma=0; i<=20; i++)
    {
        printf("Introduza a nota do test %i: ", i);
        scanf("%2.2f", teste);

        soma=soma+teste;
    }

    media=soma/20;

    printf("Media: %2.2f", media);
}
