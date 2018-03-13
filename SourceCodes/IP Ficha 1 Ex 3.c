#include <stdio.h>
#define PI 3.14

void main()
{
    float raio, perimetro, area;

    printf("Introduza o comprimento do raio do circulo: ");
    scanf("%f",&raio);

    perimetro=2*PI*raio;
    area=PI*raio*raio;

    printf("O perimetro do circulo e %5.2f e a area e %5.2f \n",perimetro,area);
    main();
}
