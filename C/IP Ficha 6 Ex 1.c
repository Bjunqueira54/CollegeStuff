#include <stdio.h>

void main()
{
    int N, i;
    printf("Insira o numero de notas que pretende inserir: ");
    scanf("%i", &N);

    float notas[N], media;
    media=0;

    for(i=1;i<=N;i++)
    {
        printf("Insira nota %i: ", i);
        scanf("%f", &notas[i-1]);
    }

    for(i=0;i<N;i++)
    {
        media+=notas[i];
    }
    media/=N;

    printf("A media das notas e: %.2f \n", media);

    for(i=0;i<N;i++)
    {
        if(notas[i]<media)
        {
            notas[i] = 0;
        }
        printf("Nota %i: %.2f \n", i+1, notas[i]);
    }
}
