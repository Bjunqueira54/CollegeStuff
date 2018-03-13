#include <stdio.h>

void desenhaEspacos(int espaco)
{
    int i;

    for(i=1;i<=espaco;i++)
    {
        printf(" ");
    }
}

void desenhaLinha(int n, int total)
{
    int espaco, k;

    espaco=total-n;

    desenhaEspacos(espaco);
    for(k=1;k<=n;k++)
    {
        printf("%i", k);
    }
    for(k=n-1;k>=1;k--)
    {
        printf("%i", k);
    }
    desenhaEspacos(espaco);
}

void main()
{
    int n, total, i;

    printf("Introduza o numero de linhas: ");
    scanf("%i", &n);
    printf("\n");

    total=n;

    for(i=1;i<=n;n--)
    {
        desenhaLinha(n, total);
        printf("\n");
    }
}
