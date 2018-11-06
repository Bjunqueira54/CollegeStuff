/*

In this code I created an algorithm that fails or passes people in olympic competitions
depending of their height and weight. Height has to be between 1.75 and 1.9 meters and weight
is between 70 and 80 Kg

*/

#include <stdio.h>

#define PESOMIN 70      //Multiple Defines. PESO = Weight and ALT = Height
#define PESOMAX 80
#define ALTMIN 1.75
#define ALTMAX 1.9

void main()
{
    float peso, altura;

    printf("Qual o peso? ");    //Asks for competitor's weight...
    scanf("%f", &peso);

    printf("Qual a altura? ");  //... and height
    scanf("%f", &altura);

    if ((peso >= PESOMIN && peso <= PESOMAX) && (altura < ALTMIN || altura > ALTMAX))   //ATTENTION TO PARENTHESIS HERE! Priority in coding is important
    {                                                                                   //First you do what's inside () first. So this if condition is first testing if
        printf("RECUSADO POR ALTURA!");   //It says here "Refused for Height"           //weight is within boundaries with "|| (or)", then checks for Height, and then checks both together
    }
    else if ((altura >= ALTMIN && altura <= ALTMAX) && (peso < PESOMIN || peso > PESOMAX))
    {
        printf("RECUSADO POR PESO!");   //It says here "Refused for Weight"
    }
    else if ((peso < PESOMIN || peso > PESOMAX) && (altura < ALTMIN || altura > ALTMAX))
    {
        printf("TOTALMENTE RECUSADO!"); //This says "Totally Refused", so height and weight weren't in boundaries
    }
    else    //In case none of the conditions above were met, that means the player is fit for competition
    {
        printf("ACEITE!");  //"ACCEPTED!"
    }
}
