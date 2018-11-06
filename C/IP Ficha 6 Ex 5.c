#include <stdio.h>

void main()
{
    long int n, i, i2, aux, a, resto, cap;

    printf("Insira um numero: ");
    scanf("%i", &n);

    cap=0;
    a=n;

    for(i=0;a!=0;i++)
    {
        a=a/10;
    }

    aux=i;

    long int num[aux];

    for(i=0;i<aux;i++)
    {
        resto = n%10;
        n/=10;
        num[i] = resto;
        //printf("%i \n", num[i]);
    }

    i2=aux;

    /*printf("------------------- \n");
    printf("%i \n", num[0]);
    printf("%i \n", num[aux-1]);
    printf("------------------- \n");*/

    for(i=0;i<i2;i++)
    {
        //printf("%i \n", num[i]);
        //printf("%i \n", num[i2-1]);

        if(num[i]==num[i2-1])
        {
            cap+=0;
        }
        else
        {
            cap+=1;
        }
        i2-=1;
    }

    if(cap==0)
    {
        printf("O numero e uma capicua! \n");
    }
    else
    {
        printf("O numero nao e uma capicua \n");
    }

    main();
}
