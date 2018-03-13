#include <stdio.h>
#define comissao 50

void main()
{
    int nFuncionario, nCarros;
    float valorVendas, salarioFixo, valorCarro, salarioMensal;

    printf("Numero de Funcionario: ");
    scanf("%i",&nFuncionario);

    printf("Numero de carros vendidos: ");
    scanf("%i",&nCarros);

    printf("Valor recebido por carro: ");
    scanf("%f",&valorCarro);

    printf("Salario fixo: ");
    scanf("%f",&salarioFixo);

    valorVendas=valorCarro*nCarros;
    salarioMensal=salarioFixo+(comissao*nCarros)+(valorVendas*0.05);

    printf("O Funcionario numero %i recebeu neste mes um total de %4.2f Euros.",nFuncionario,salarioMensal);
}
