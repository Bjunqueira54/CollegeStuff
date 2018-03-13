#include <stdio.h>

void main()
{
    int n, i, k;

    printf("Introduza o tamanho dos lados: ");
    scanf("%i", &n);

    printf("\n");

    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n;k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
