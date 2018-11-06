/*

Calculates taxi average gas consumption, profit made and car performance

*/

#include <stdio.h>

#define PC 1.3  //PC = (portuguese) Car Performance Percentage. 30%

void main()
{
    float kmi,kmf,valor,litros; //dados de entrada. Input Data
    float media,lucro,rend; //dados de saida. Output Data

    printf("Valor do conta-quilometros no inicio do dia?: ");   //Car distance counter at the start of the day?
    scanf("%f",&kmi);

    printf("Valor do conta-quilometros no final do dia?: ");    //Car distance counter at the end of the day?
    scanf("%f",&kmf);

    printf("Valor total recebido pelo clientes?: ");    //Total cash got from clients?
    scanf("%f",&valor);

    printf("Litros de gasolina gastos durante o dia?: ");   //Liters of gas spent during the day?
    scanf("%f",&litros);

    media=((kmf-kmi)/litros);   //Average consumption: (end distance - start distance) / Liters
    lucro=(valor-(litros*PC));  //Profit: Total Cash - (130% of Gas Spent)
    rend=(100*((valor/(litros*PC))-1)); //Car performance. My teacher gave me this formula. No idea wtf this is

    printf("A media do consumo hoje foi de %fKm/L \n",media);
    printf("O lucro do dia de hoje foi de %f Euros \n",lucro);
    printf("O Rendimento do carro e de %f%% \n",rend);
}
