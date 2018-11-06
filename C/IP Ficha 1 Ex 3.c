/*

This code serves to calculate the perimeter and the area of a circle

*/

#include <stdio.h>

#define PI 3.14

void main()
{
    float raio, perimetro, area;    //All float variables

    printf("Introduza o comprimento do raio do circulo: "); //gets half of the diameter of the circle. (I forgot the word, ok? :c)
    scanf("%f",&raio);

    perimetro=2*PI*raio;    //Circle Perimeter formula
    area=PI*raio*raio;      //Circle Area formula

    printf("O perimetro do circulo e %5.2f e a area e %5.2f \n", perimetro, area);    //prints results to terminal
    main(); //Again this recursive shit.... don't do this, please!
}
