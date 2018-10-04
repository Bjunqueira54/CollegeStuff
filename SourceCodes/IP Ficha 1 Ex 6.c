/*

This is a basic vote counter for elections. 
Counts total votes, and then the percentage of valid votes, blank votes and null votes

*/

#include <stdio.h>

void main()
{
    float validos, brancos, nulos, total;

    printf("Numero de votos validos: ");    //Gets number of valid votes
    scanf("%f",&validos);

    printf("Numero de votos brancos: ");    //Gets number of blank votes
    scanf("%f",&brancos);

    printf("Numero de votos nulos: ");      //Gets number of null votes
    scanf("%f",&nulos);

    total=validos+brancos+nulos;    //Calculates total votes by adding all other 3
    float pV=(validos/total)*100;   //Creates new float vars and imediatelly initializes them with the percentage calculations
    float pB=(brancos/total)*100;
    float pN=(nulos/total)*100;

    printf("O numero total de votos foi %5.0f; \n",total);  //PRINT ALL ZE INFO!
    printf("Com %5.2f%% de votos validos, \n",pV);
    printf("Com %5.2f%% de votos brancos, \n",pB);
    printf("Com %5.2f%% de votos nulos. \n",pN);
}
