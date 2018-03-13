#include <stdio.h>

void main()
{
    int numero1, numero2, numero3;

    printf("Numero 1: \n");
    scanf("%i", &numero1);
    printf("Numero 2: \n");
    scanf("%i", &numero2);
    printf("Numero 3: \n");
    scanf("%i", &numero3);

    if (numero1 > numero2 && numero1 > numero3)
    {
        printf("O maior numero e o numero %i", numero1);
    }
    else if (numero2 > numero1 && numero2 > numero3)
    {
        printf("O maior numero e o numero %i", numero2);
    }
    else
    {
        printf("O maior numero e o numero %i", numero3);
    }
}
