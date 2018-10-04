/*

This simple code simply calculates job pay with taxes and without taxes.

*/

#include <stdio.h>

#define TAXA_IRS 0.25   //Our defines :)
#define TAXA_SS 0.11

void main()
{
    float ordenadoIliquido, ordenadoLiquido, valorSS, valorIRS; //Our float variables. We'll be using multiplications and percentage operations

    printf("Valor do ordenado Iliquido: "); //Gets users job pay without taxes first
    scanf("%f", &ordenadoIliquido);

    valorSS=ordenadoIliquido*TAXA_SS;   //Calculates SS and IRS tax
    valorIRS=ordenadoIliquido*TAXA_IRS;
    ordenadoLiquido=ordenadoIliquido-valorSS-valorIRS; //User's end payment is original payment - both taxes

    printf("O seu ordenado liquido e %5.2f Euros,\n"
           "descontou %5.2f Euros para a Segurança Social e \n"
           "descontou %5.2f Euros para o IRS.",ordenadoLiquido, valorSS, valorIRS); //Prints his liquid payment and how much taxes he had to pay for what type
}
