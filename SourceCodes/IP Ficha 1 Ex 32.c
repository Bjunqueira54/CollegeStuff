#include <stdio.h>

void main()
{
    int n, soma;

    printf("Introduza um numero inteiro: ");
    scanf("%10i", &n);

    soma=0;

    while(n>0)
    {
        soma=soma+(n%10);
        n=n/10;
    }

    printf("A soma dos digitos e %d", soma);
}
