#include <stdio.h>  //included library. STandard Input Out

void main() //main function. VOID returns nothing
{
    int valor, horas, minutosIntermedio, minutos, segundos; //multiple INTegers variables

    printf("Introduza o valor total de segundos: ");    //Asking for total amount of seconds. Example: 3600s  = 1 hour
    scanf("%i",&valor); //scans the input for a %i and stores it into "valor"

    horas=valor/3600;   //since 1 hour = 3600 seconds => (total seconds)/3600
    minutosIntermedio=valor%3600;   // % is basically what's left of a division that doesn't return a float. Example: 5 % 2 = 1 (2 fits into 5 twice, but the 1 is left out)
    minutos=minutosIntermedio/60;   // Whatever is left from the above operation is divided into the total amount of seconds in a minute
    segundos=minutosIntermedio%60;  // And lastly, since we don't calculate miliseconds here, this operation is to find out of many seconds in a minute are still left

    printf("O tempo convertido e %i Horas %i Minutos e %i Segundos. \n", horas, minutos, segundos); //Prints the vars to screen
}
