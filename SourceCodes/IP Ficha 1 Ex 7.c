#include <stdio.h>

#define PC 1.3

void main()
{
    float kmi,kmf,valor,litros; //dados de entrada
    float media,lucro,rend; //dados de saida

    printf("Valor do conta-quilometros no inicio do dia?: ");
    scanf("%f",&kmi);

    printf("Valor do conta-quilometros no final do dia?: ");
    scanf("%f",&kmf);

    printf("Valor total recebido pelo clientes?: ");
    scanf("%f",&valor);

    printf("Litros de gasolina gastos durante o dia?: ");
    scanf("%f",&litros);

    media=((kmf-kmi)/litros);
    lucro=(valor-(litros*PC));
    rend=(100*((valor/(litros*PC))-1));

    printf("A media do consumo hoje foi de %fKm/L \n",media);
    printf("O lucro do dia de hoje foi de %f Euros \n",lucro);
    printf("O Rendimento do carro e de %f%% \n",rend);
}
