#include <stdio.h>

void adicao(float n1, float n2)
{
    float resultado;
    resultado=n1+n2;
    printf("O resultado e %5.2f \n",resultado);
}
void subtracao(float n1,float n2)
{
    float resultado;
    resultado=n1-n2;
    printf("O resultado e %5.2f \n",resultado);
}
void multi(float n1, float n2)
{
    float resultado;
    resultado=n1*n2;
    printf("O resultado e %5.2f \n",resultado);
}
void divisao(float n1, float n2)
{
    float resultado;
    resultado=n1/n2;
    printf("O resultado e %5.2f \n",resultado);
}

void main()
{
    float n1,n2;
    int tipo;

    printf("Introduza um numero: ");
    scanf("%f",&n1);

    printf("Introduza outro numero: ");
    scanf("%f",&n2);

    printf("Escolha o tipo de operacao: \n"
            "1 - Adicao \n"
            "2 - Subtracao \n"
            "3 - Multiplicacao \n"
            "4 - Divisao \n"
            "Tipo: ");
    scanf("%i",&tipo);

    switch(tipo)
    {
        case 1: adicao(n1,n2); break;
        case 2: subtracao(n1,n2); break;
        case 3: multi(n1,n2); break;
        case 4: divisao(n1,n2);
    }
    main();
}
