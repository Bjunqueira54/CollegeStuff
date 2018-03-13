#include <stdio.h>

int divisores(int n)
{
    int i, div, resto;

    div=0;

    for(i=1;i<=n;i++)
    {
        resto=n%i;

        if(resto==0)
        {
            div++;
        }
    }

    return div;
}

void main()
{
    int num, div;

    do
    {
        printf("Introduza um numero: ");
        scanf("%i", &num);

        div=divisores(num);

        if(div==2)
        {
            printf("NUMERO PRIMO! \n");
        }
    }
    while(num>0);
}
