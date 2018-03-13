#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

void Duplicador(char frase[], char letra, int tam)
{
    int i, j;

    for(i=0; frase[i] == ' '; i++)
    {
        ;
    }

    for(; frase[i]!='\0'; i++)
    {
        if(frase[i] == letra)
        {
            for(j=tam; j>i; j--)
            {
                frase[j] = frase[j-1];
            }
            frase[tam+1] = '\0';
            i++;
        }
        tam = strlen(frase);
    }

    printf("%s", frase);
}

void main()
{
    char frase[MAX], letra;

    int tam;

    printf("Escreva uma frase: ");
    gets(frase);

    printf("\nEscolha uma letra a duplicar: ");
    scanf("%c", &letra);

    tam = strlen(frase);
    printf("\n%i\n", tam);

    Duplicador(frase, letra, tam);

}
