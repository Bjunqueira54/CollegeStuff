#include <stdio.h>

void main()
{
    int nPos, nSize, nMax, n;

    nSize = 0;
    nMax = 0;

    do
    {
        printf("introduza um numero: ");
        scanf("%i", &n);

        if(n > 0)
        {
            nSize = nSize + 1;

            if(n > nMax)
            {
                nMax = n;
                nPos = nSize;
            }
        }
        else if (n < 0)
        {
            printf("Numero Invalido");
        }

    }
    while(n != 0);

    printf("A sequencia tinha %i numeros, o maior foi %i e surgiu na posicao %i", nSize, nMax, nPos);
}
