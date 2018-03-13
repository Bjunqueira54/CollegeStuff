#include <stdio.h>

void main()
{
    int n1, n2, n3;

    printf("Numero 1: ");
    scanf("%i", &n1);

    printf("Numero 2: ");
    scanf("%i", &n2);

    printf("Numero 3: ");
    scanf("%i", &n3);

    if (n1 > n2 && n1 > n3)
    {
        if (n2 > n3)
        {
            printf("%i < %i < %i", n3, n2, n1);
        }
        else
        {
            printf("%i < %i < %i", n2, n3, n1);
        }
    }
    else if (n2 > n1 && n2 > n3)
    {
        if (n1 > n3)
        {
            printf("%i < %i < %i", n3, n1, n2);
        }
        else
        {
            printf("%i < %i < %i", n1, n3, n2);
        }
    }
    else if (n3 > n1 && n3 > n2)
    {
        if (n1 > n2)
        {
            printf("%i < %i < %i", n2, n1, n3);
        }
        else
        {
            printf("%i < %i < %i", n1, n2, n3);
        }
    }
}
