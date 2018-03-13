#include <stdio.h>

void main()
{
    int nSal;
    float sal, salMaior, salMenor, somaSal, media;

    somaSal=0;
    nSal=0;
    salMaior=0;
    salMenor=99999999999999;

    while(sal>0)
    {
        printf("Introduza um Salario: ");
        scanf("%f", &sal);
        printf("\n");

        if(sal>0)
        {
            somaSal=somaSal+sal;
            nSal=nSal+1;

            if(sal>salMaior)
            {
                salMaior=sal;
            }

            if(sal<salMenor)
            {
                salMenor=sal;
            }
        }
        else
        {
            printf(" ");
        }
    }

    media=(somaSal/nSal);
    printf("A media do salario de %i trabalhadores e de %8.2f euros. \n", nSal, media);
    printf("O maior salario e %8.2f e o menor salario e %8.2f.", salMaior, salMenor);
}
