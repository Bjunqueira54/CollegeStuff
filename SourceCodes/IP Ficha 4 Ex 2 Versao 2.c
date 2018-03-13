#include <stdio.h>

void main()
{
    int nTrab, nSal;
    float sal, media, somaSal;

    somaSal=0;
    nSal=0;

    printf("Numero de Trabalhadores: ");
    scanf("%i", &nTrab);
    printf("\n");

    while(nSal<nTrab)
    {
        printf("Introduza um salario: ");
        scanf("%f", &sal),
        printf("\n");

        somaSal=somaSal+sal;
        nSal=nSal+1;
    }

    media=(somaSal/nSal);

    printf("A media dos salarios de %i trabalhadores e de %5.2f euros", nTrab, media);

}
