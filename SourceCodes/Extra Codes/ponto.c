#include <stdio.h>

void main()
{
    float x, y;

    printf("Qual a abcissa do ponto x: ");
    scanf("%f", &x);

    printf("Qual a ordenada do ponto y: ");
    scanf("%f", &y);

    if (x>0 && y > 0)
    {
        printf("1 Quadrante");
    }
    else if (x<0 && y>0)
    {
        printf("2 Quadrante");
    }
    else if(x<0 && y<0)
    {
        printf("3 Quadrante");
    }
    else if (x>0 && y<0)
    {
        printf("4 Quadrante");
    }
    else if (x==0 && y==0)
    {
        printf("Origem dos eixos");
    }
    else if (x==0 && y!=0)
    {
        printf("Eixo das ordenadas");
    }
    else if (x!=0 && y==0)
    {
        printf("Eixo das Abcissas");
    }
}
