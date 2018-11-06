#include <stdio.h>
#include <ctype.h>

int classificaLetra(char c)
{
    switch(c)
    {
        case 'a': return 1; break;
        case 'e': return 2; break;
        case 'i': return 3; break;
        case 'o': return 4; break;
        case 'u': return 5; break;
        default: return 0;
    }
}

void main()
{
    char c, cl;

    printf("Introduza 1 letra: ");
    fflush(stdin);
    scanf("%c", &c);

    c=tolower(c);
    cl=classificaLetra(c);

    printf("Classificacao: %i", cl);
}
