#include <stdio.h>

int Calculo(int vetor[], int tam)
{
    int i, maior = vetor[0] , soma = 0, contador = 0;

    for(i=0; i<tam; i++)
    {
        if(vetor[i]>maior)
        {
            contador = 1;
            maior = vetor[i];
        }
        else if (vetor[i] == maior)
        {
            contador += 1;
        }
    }

    soma = maior * contador;

    return soma;
}

void main()
{
    int tam, i, n;

    printf("Quantos numero deseja inserir? ");
    scanf("%i", &tam);

    int vec[tam];

    for(i=0;i<tam;i++)
    {
        printf("Insira um numero inteiro: ");
        scanf("%i", &vec[i]);
    }

    n=Calculo(vec, tam);
    printf("A soma da maior occurencia e %i \n", n);

    main();
}
