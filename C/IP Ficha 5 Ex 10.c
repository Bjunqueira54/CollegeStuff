#include <stdio.h>

long int Cubo(int n)
{

    n=n*n*n;
    //printf("Cubo local = %i \n", n);

    return n;
}

int num()
{
    int n;

    printf("Introduza um numero positivo entre 100 e 999: ");
    scanf("%i", &n);

    if(n<100 || n>999)
    {
        printf("Numero Invalido! \n");
        num();
    }

    return n;
}

int Verifica(int n)
{
    int soma, cube, resto, resto1, d1, d2, d3, aux;
    //printf("n = %i \n", n);
    //cube=Cubo(n);
    aux=n;
    //printf("Cubo = %i \n", cube);
    resto=n%100;
    aux=aux/100;
    resto1=resto%10;
    resto=resto/10;
    d1=Cubo(aux);
    //printf("d1 = %i \n", d1);
    d2=Cubo(resto);
    //printf("d2 = %i \n", d2);
    d3=Cubo(resto1);
    //printf("d3 = %i \n", d3);

    soma=d1+d2+d3;
    //printf("soma= %i \n", soma);

    if(soma==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void main()
{
    char conf;
    int ver, n;

    do
    {
        n=num();
        ver=Verifica(n);

        if(ver==1)
        {
            printf("O cubo do numero e igual a soma dos cubos dos seu elementos. \n");
        }
        else if(ver==0)
        {
            printf("O cubo do numero e nao igual a soma dos cubos dos seu elementos. \n");
        }
        printf("Deseja continua?(S ou s/Outro = nao): ");
        fflush(stdin);
        scanf("%c", &conf);
    }
    while(conf=='s' || conf=='S');
}
