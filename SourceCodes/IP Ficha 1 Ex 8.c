#include <stdio.h>
#define TAXA_IRS 0.25
#define TAXA_SS 0.11

void main()
{
    float ordenadoIliquido, ordenadoLiquido, valorSS, valorIRS;

    printf("Valor do ordenado Iliquido: ");
    scanf("%f",&ordenadoIliquido);

    valorSS=ordenadoIliquido*TAXA_SS;
    valorIRS=ordenadoIliquido*TAXA_IRS;
    ordenadoLiquido=ordenadoIliquido-valorSS-valorIRS;

    printf("O seu ordenado liquido e %5.2f Euros,\n"
           "descontou %5.2f Euros para a Segurança Social e \n"
           "descontou %5.2f Euros para o IRS.",ordenadoLiquido, valorSS, valorIRS);
}
