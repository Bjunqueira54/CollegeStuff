#include <stdio.h>
#include <string.h>

int Contador(char frase[])
{
    int cont, i, primeiro, tam;
    tam=strlen(frase);
    cont = 0;

    for(i=0; frase[i]== ' '; i++);
    primeiro=tolower(frase[0]);

    for(;frase[i]!='\0'; i++)
    {
        if(tolower(frase[i])==primeiro)
        {
            cont++;
        }
    }
    return cont;
}

void main()
{
    char frase[50];
    gets(frase);

    int iguais;

    iguais = Contador(frase);

    printf("O numero de characters iguais ao primeiro, inclusive, e %i", iguais);
}
