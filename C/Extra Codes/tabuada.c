#include <stdio.h>

void main()
{
    int i, numero;

    printf("Numero: ");
    scanf("%d", &numero);

    for (i=1;i<=10;i++)
        printf("%2d*%2d=%2d \n", numero, i, numero*i);
}
