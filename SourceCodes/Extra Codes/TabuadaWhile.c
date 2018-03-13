#include <stdio.h>

void main()
{
    int i=1, numero;

    printf("Numero: ");
    scanf("%d", &numero);
     while (i<=10)
     {
         printf("%2d*%2d=%2d \n", numero, i, numero*i);
         i++;
     }
}
