#include <stdio.h>

float calcIMC(float kg, float mt)
{
    float imc;

    imc=((kg)/(mt*mt));

    printf("IMC: %5.2f \n", imc);

    return imc;
}

void main()
{
    int p,i;
    float kg, m, imc;

    printf("introduza o numero de pessoas: ");
    scanf("%i", &p);

    for(i=1;i<=p;i++)
    {
        printf("Introduza Peso: ");
        scanf("%f", &kg);

        printf("Introduza Altura: ");
        scanf("%f", &m);

        imc=calcIMC(kg, m);

        if(imc<=18.5)
        {
            printf("Abaixo do peso Normal \n");
        }
        else if(imc>18.5 && imc<25)
        {
            printf("Peso Normal \n");
        }
        else if(imc>25 && imc<=30)
        {
            printf("Acima do peso Normal \n");
        }
        else
        {
            printf("Obesidade \n");
        }
    }
}
