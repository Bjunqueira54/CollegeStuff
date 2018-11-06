#include <stdio.h>

void main()
{
    int nSal;
    float sal, media, somaSal;

    nSal=0;
    somaSal=0;

    while(sal>0)
    {
        printf("Introduza Salario: ");
        scanf("%f", &sal);
        printf("\n");

        if(sal>0)
        {
            somaSal=somaSal+sal;
            nSal=nSal+1;
        }
        else
        {
            printf("\n");
        }
    }

    media=(somaSal/nSal);
    printf("A media do salario de %i Trabalhadores e de %f euros.", nSal, media);
}
