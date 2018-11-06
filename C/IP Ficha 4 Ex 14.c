#include <stdio.h>
#include <math.h>

void main()
{
    int i, num, copia, exp, resto, soma, n1;

    exp=0;

    for(i=10;num!=(4*i);i++)
    {
        copia=i;

        resto=copia%10;

        while(copia>0)
        {
            copia=copia/10;
            exp++;
        }

        copia=copia/10;

        n1=pow(10, exp);
        soma=resto*n1;
        num=soma+copia;
    }

    printf("O menor numero inteiro e %i", num);
}
