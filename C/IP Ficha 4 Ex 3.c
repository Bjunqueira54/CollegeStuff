#include <stdio.h>
#define TAXA_A 1.06
#define TAXA_NA 1.23

void main()
{
    int tipo, nProdA, nProdNA, nProd;
    float precoProd, precoProdIVA, total, totalIVA;

    nProdA = 0;
    nProdNA = 0;
    total=0;
    totalIVA=0;

    while(precoProd>0)
    {
        printf("Introduza preco: ");
        scanf("%f", &precoProd);
        //printf("\n");

        if(precoProd>0)
        {
            printf("Introduza o tipo de Produto(1 - Alimentar | 0 - Nao Alimentar): ");
            scanf("%i", &tipo);

            if(tipo==0)
            {
                precoProdIVA=precoProd*TAXA_NA;
                total=total+precoProd;
                totalIVA=totalIVA+precoProdIVA;
                nProdNA=nProdNA+1;
            }
            else
            {
                precoProdIVA=precoProd*TAXA_A;
                total=total+precoProd;
                totalIVA=totalIVA+precoProdIVA;
                nProdA=nProdA+1;
            }

        }
        else
        {
            printf("\n");
        }
        nProd=nProdA+nProdNA;
    }

    printf("Talao: \n");
    printf("Total: %10.2f \n", total);
    printf("Total Apos IVA: %10.2f \n", totalIVA);
    printf("Produtos Alimentares: %i \n", nProdA);
    printf("Produtos Nao-Alimentares: %i \n", nProdNA);
    printf("Total de produtos: %i", nProd);
}
