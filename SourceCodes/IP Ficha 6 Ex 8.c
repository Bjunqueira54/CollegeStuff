#include <stdio.h>
#define DIM_TAM 10

void Orderna(int vetor[], int tam)
{
    int i, j, maior, pos, posVec2;

    int vec2[DIM_TAM];

    maior = vetor[0];
    pos=0;

    for(i=0; i<tam; i++)
    {
        if (maior<vetor[i])
        {
            maior = vetor[i];
            pos = i;
        }
    }

    vec2[0]=maior;
    posVec2=1;

    for(i=pos+1, j=pos-1; i<=DIM_TAM && j>=0; i++, j--)
    {
        if(i==DIM_TAM)
        {
            for(j=j; j>=0; j--)
            {
                vec2[posVec2]=vetor[j];
            }
        }
        else if(j<0)
        {
            for(i=i; i<DIM_TAM; i++)
            {
                vec2[posVec2]=vetor[i];
            }
        }
        else if(vetor[i]>vetor[j])
        {
            vec2[posVec2]=vetor[i];
            j++;
        }
        else if (vetor[j]>vetor[i])
        {
            vec2[posVec2]=vetor[j];
            i--;
        }
        posVec2++;
    }

    for(i=0;i<tam;i++)
    {
        printf("%i ", vec2[i]);
    }
}

void main()
{
    int i;
    int vec[DIM_TAM];

    for(i=0;i<DIM_TAM;i++)
    {
        printf("Introduza um numero de array piramide: ");
        scanf("%i", &vec[i]);
        fflush(stdin);
    }

    Orderna(vec, DIM_TAM);
}
