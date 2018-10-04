/*

In this code I created the most basic calculator of them all.

*/

#include <stdio.h>

void adicao(float n1, float n2) //simple function that takes 2 float parameters...
{
    float resultado;    //... creates a result var
    resultado=n1+n2;    //... and adds them
    printf("O resultado e %5.2f \n",resultado);
}
void subtracao(float n1,float n2)   //simple function that takes 2 float parameters...
{
    float resultado;    //... creates a result var
    resultado=n1-n2;    //... and subtracts them
    printf("O resultado e %5.2f \n",resultado);
}
void multi(float n1, float n2)  //You get the point...
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
    float n1,n2;    //2 floats for all operations
    int tipo;

    printf("Introduza um numero: ");    //Gets numbers from user
    scanf("%f",&n1);

    printf("Introduza outro numero: ");
    scanf("%f",&n2);

    printf("Escolha o tipo de operacao: \n"     //Basic Menu
            "1 - Adicao \n"
            "2 - Subtracao \n"
            "3 - Multiplicacao \n"
            "4 - Divisao \n"
            "Tipo: ");
    scanf("%i",&tipo);  //Gets user's choice

    switch(tipo)    //A switch(){} can replace "if\else" conditions. Usage: switch(var){ case VAR.VALUE: Instructions; break}
    {
        case 1: adicao(n1,n2); break;
        case 2: subtracao(n1,n2); break;
        case 3: multi(n1,n2); break;
        case 4: divisao(n1,n2);
    }
    main();
}
