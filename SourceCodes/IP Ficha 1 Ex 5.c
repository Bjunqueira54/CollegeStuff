/*

Algorithm that calculates how much an auto-stand employee will
recieve at the end of the month

*/

#include <stdio.h>

#define comissao 50 //Our comission per sold car

void main()
{
    int nFuncionario, nCarros;
    float valorVendas, salarioFixo, valorCarro, salarioMensal;

    printf("Numero de Funcionario: ");  //Employee number
    scanf("%i",&nFuncionario);

    printf("Numero de carros vendidos: ");  //Cars sold
    scanf("%i",&nCarros);

    printf("Valor recebido por carro: ");   //Cash recieved per car
    scanf("%f",&valorCarro);

    printf("Salario fixo: ");   //Regular salary
    scanf("%f",&salarioFixo);

    valorVendas=valorCarro*nCarros; //Sales = cars sold * car price
    salarioMensal=salarioFixo+(comissao*nCarros)+(valorVendas*0.05);    //Monthly Salary = Regular + (Comission*cars sold) + (5% of Sales)

    printf("O Funcionario numero %i recebeu neste mes um total de %4.2f Euros.", nFuncionario, salarioMensal);  //Print information
}
