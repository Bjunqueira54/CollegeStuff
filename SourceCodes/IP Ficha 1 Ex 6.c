#include <stdio.h>

void main()
{
    float validos, brancos, nulos, total;

    printf("Numero de votos validos: ");
    scanf("%f",&validos);

    printf("Numero de votos brancos: ");
    scanf("%f",&brancos);

    printf("Numero de votos nulos: ");
    scanf("%f",&nulos);

    total=validos+brancos+nulos;
    float pV=(validos/total)*100;
    float pB=(brancos/total)*100;
    float pN=(nulos/total)*100;

    printf("O numero total de votos foi %5.0f; \n",total);
    printf("Com %5.2f%% de votos validos, \n",pV);
    printf("Com %5.2f%% de votos brancos, \n",pB);
    printf("Com %5.2f%% de votos nulos. \n",pN);
}
