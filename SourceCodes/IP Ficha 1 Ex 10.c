#include <stdio.h>

void main()
{
    int valor, horas, minutosIntermedio, minutos, segundos;

    printf("Introduza o valor total de segundos: ");
    scanf("%i",&valor);

    horas=valor/3600;
    minutosIntermedio=valor%3600;
    minutos=minutosIntermedio/60;
    segundos=minutosIntermedio%60;

    printf("O tempo convertido e %i Horas %i Minutos e %i Segundos. \n", horas, minutos, segundos);
}
