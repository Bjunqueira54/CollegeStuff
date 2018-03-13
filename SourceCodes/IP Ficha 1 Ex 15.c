#include <stdio.h>

void calcPerimetro(float lado, int nLados)
{
    float perimetro;

    perimetro=lado*nLados;

    printf("O perimetro do triangulo e %5.2f",perimetro);
}

void calcArea(float lado)
{
    float area;

    area=lado*lado;

    printf("A area do quadrado e %5.2f",area);
}

void main()
{
    float lado;
    int nLados;

    printf("Numero de lados: ");
    scanf("%i",&nLados);

    if (nLados==3 || nLados==4)
    {
        printf("Medida dos lados: ");
        scanf("%f",&lado);

        if (nLados==3)
        {
            printf("Triangulo! \n");
            calcPerimetro(lado,nLados);
        }

        else if (nLados==4)
        {
            printf("Quadrado! \n");
            calcArea(lado);
        }
    }

    else if (nLados==5)
    {
        printf("Pentagono! \n");
    }
    else
    {
        printf("Numero de lados invalido. \n");
        main();
    }
}
