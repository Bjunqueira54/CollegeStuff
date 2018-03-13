#include <stdio.h>

void main()
{
    int dia, mes, ano, ultimodia;

    printf("Introduza a data no formato DD/MM/AAAA: ");
    scanf("%2i/%2i/%4i", &dia, &mes, &ano);

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        ultimodia = 30;
    }
    else if (mes == 2)
    {
        ultimodia = 28;
    }
    else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        ultimodia = 31;
    }
    else
    {
        printf("Mes invalido!");
    }

    if (dia == ultimodia)
    {
        if (mes == 12)
        {
            dia = 1;
            mes = 1;
            ano = ++ano;
        }
        else
        {
            dia = 1;
            mes = ++mes;
        }
    }
    else
    {
        dia = ++dia;
    }

    printf("A data amanha sera %i/%i/%i", dia, mes, ano);
}
