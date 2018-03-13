#include <stdio.h>

void main()
{
    int contador, expoente;
    float base, potencia;

    printf("Base: ");
    scanf("%f", &base);

    printf("Expoente: ");
    scanf("%f", &expoente);

    for (potencia=1, contador=0; contador<expoente; contador++)
        potencia*=base;

    printf("Valor da potencia = %.1f \n", potencia);
}
