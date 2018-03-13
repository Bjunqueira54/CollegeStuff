#include <stdio.h>
#define PESOMIN 70
#define PESOMAX 80
#define ALTMIN 1.75
#define ALTMAX 1.9

void main()
{
    float peso, altura;

    printf("Qual o peso? ");
    scanf("%f", &peso);

    printf("Qual a altura? ");
    scanf("%f", &altura);

    if ((peso >= PESOMIN && peso <= PESOMAX) && (altura < ALTMIN || altura > ALTMAX))
    {
        printf("RECUSADO POR ALTURA!");
    }
    else if ((altura >= ALTMIN && altura <= ALTMAX) && (peso < PESOMIN || peso > PESOMAX))
    {
        printf("RECUSADO POR PESO!");
    }
    else if ((peso < PESOMIN || peso > PESOMAX) && (altura < ALTMIN || altura > ALTMAX))
    {
        printf("TOTALMENTE RECUSADO!");
    }
    else
    {
        printf("ACEITE!");
    }
}
