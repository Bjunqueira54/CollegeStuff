#include <stdio.h>
#include <string.h>
#define TAM 50

void main()
{
    char frase[TAM];
    int i=0;
    gets(frase);

    while(frase[i]!='\0')
    {
        for(;frase[i]==' '; i++);
        for(;frase[i]!=' ' && frase[i]!='\0'; i++)
        {
            printf("%c", frase[i]);
        }

        printf("\n");
    }
}
