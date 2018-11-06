#include <stdio.h>
#define MAX 101

void main()
{
    char frase[MAX], palavra[MAX], outra[MAX];
    int cont=0, j, i=0;

    printf("Introduza uma frase: ");
    gets(frase);

    while(frase[i]==' ')
    {
        i+=1;
    }

    for(j=0;frase[i]!=' ' && frase[i]!='\0';j++, i++)
    {
        palavra[j]=tolower(frase[i]);
    }
    palavra[j]='\0';
    i=0;

    while(frase[i]!='\0')
    {
        while(frase[i]==' ')
        {
            i++;
        }

        for(j=0;frase[i]!=' ' && frase[i]!='\0';j++, i++)
        {
            outra[j]=tolower(frase[i]);
        }

        outra[j]='\0';

        if(strcmp(outra, palavra)==0)
        {
            cont++;
        }
    }

    printf("A primeira palavra da frase e: %s e foi repetida %i vezes", palavra, cont);
}
