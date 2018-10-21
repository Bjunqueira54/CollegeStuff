#include <stdio.h>
#include <stdlib.h>
#define COOP 0.75
#define PRODBRANCO 0.6

int main(int argc, char** argv) 
{
   float qtd_proprio, qtd_branco, qtd_tinto, qtd_coop, qtd_colhidas ;
      
    printf("Qual a quantidade de uvas colhidas:");
    scanf("%f",&qtd_colhidas);
    
    qtd_coop = COOP * qtd_colhidas;
    qtd_proprio = qtd_colhidas - qtd_coop;
    qtd_branco = PRODBRANCO * qtd_colhidas;
    qtd_tinto = qtd_coop - qtd_branco;
    
    printf("Consumo Proprio:%5.2f\n" "Vinho Branco: %5.2f\n" 
            "Vinho Tinto:%5.2f\n" 
            "Cooperativa:%5.2f\n", qtd_proprio,qtd_branco, qtd_tinto, qtd_coop);
            
    return (EXIT_SUCCESS);
}
