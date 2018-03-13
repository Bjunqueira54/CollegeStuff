#include <stdio.h>

int FindHigher(int vec[], int tam)
{
    int i, pos, maior = vec[0];

    for(i=0;i<tam;i++)
    {
        if(vec[i]>= maior)
        {
            maior = vec[i];
            pos = i;
        }
    }
    printf("%i \n", pos);
    return pos;
}

void ShiftRight(int vec[], int tam)
{
    int i, aux;
    aux=vec[tam-1];
    for(i=tam;i>0;i--)
    {
        vec[i]=vec[i-1];
    }
    vec[0]=aux;

}

void ShiftRightHigh(int vec[], int tam, int maior)
{
    while(vec[tam-1]!=maior)
        ShiftRight(vec, tam);
}

void main()
{
    int tam, pos, i, maior;

    printf("Quantos componentes deseja? ");
    scanf("%i", &tam);

    int vec[tam];

    for(i=0; i<tam; i++)
    {
        printf("Introduza um numero: ");
        scanf("%i", &vec[i]);
    }

    pos=FindHigher(vec, tam);
    maior=vec[pos];
    printf("O maior numero e %i na posicao %i \n", vec[pos], pos+1);

    ShiftRight(vec, tam);

    for(i=0; i<tam; i++)
    {
        printf("pos %i : %i \n", i, vec[i]);
    }

    ShiftRightHigh(vec, tam, maior);

    printf("----------------- \n");

    for(i=0; i<tam; i++)
    {
        printf("pos %i : %i \n", i, vec[i]);
    }
}
