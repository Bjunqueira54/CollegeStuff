#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void main()
{
    char frase[MAX], palavra[20], aux[20];
    int i=0, j, dim, pos, dimaux;

    printf("Introduza uma frase: ");
    gets(frase);

    printf("Agora uma palavra: ");
    gets(palavra);

    dim = strlen(palavra);

    while(frase[i]!='\0')
    {
        for(;frase[i]==' ' && frase[i]!='\0'; i++);

        pos = i;

        for(j=0;frase[i]!=' ' && frase[i]!='\0';i++, j++)
        {
            aux[j]=frase[i];
        }

        aux[j]='\0';

        dimaux = strlen(aux);

        if(dimaux == dim)
        {
            i=pos;
            j=0;
            for(;frase[i]!=' ' && frase[i]!='\0' ;i++, j++)
            {
                frase[i]=palavra[j];
            }
            break;
        }
    }

    printf("%s \n", frase);
    printf("%s \n", palavra);
    printf("%s \n", aux);
    printf("%i \n", pos);
    printf("%i \n", dimaux);
}
