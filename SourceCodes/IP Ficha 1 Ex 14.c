#include <stdio.h>
#define ESSENCIAL 1.05
#define LUXO 1.3
#define RESTANTES 1.2

void main()
{
    float valorArtigo, valorArtigoIVA;
    int tipoArtigo;

    printf("Qual o valor do artigo?: ");
    scanf("%f", &valorArtigo);
    printf("\n");

    printf("Qual o tipo de artigo?: \n"
           "1 - Essencial \n"
           "2 - Luxo \n"
           "3 - Restantes \n");
    scanf("%i", &tipoArtigo);
    printf("\n");

    if (tipoArtigo == 1)
    {
        valorArtigoIVA=valorArtigo*ESSENCIAL;
        printf("O valor com IVA do artigo e %5.2f Euros", valorArtigoIVA);
    }
    else if (tipoArtigo == 2)
    {
        valorArtigoIVA=valorArtigo*LUXO;
        printf("O valor com IVA do artigo e %5.2f Euros", valorArtigoIVA);
    }
    else
    {
        valorArtigoIVA=valorArtigo*RESTANTES;
        printf("O valor com IVA do artigo e %5.2f Euros", valorArtigoIVA);
    }
}
