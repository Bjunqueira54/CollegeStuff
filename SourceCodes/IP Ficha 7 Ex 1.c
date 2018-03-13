#include <stdio.h>
#include <string.h>

void main()
{
    char frase[50];

    gets(frase);

    int i, tam=strlen(frase);

    for(i=tam-1;i>=0;i--)
    {
        printf("%c", frase[i]);
    }
}
