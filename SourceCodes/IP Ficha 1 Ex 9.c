/*

Here we ask the user for 3 numbers, and the algorithm shall order from lowest to highest with multiple if\else conditions.

*/

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

    if (n1 > n2 && n1 > n3) //if n1 is the highest number
    {
        if (n2 > n3)    //test to see if n2 is higher than n3
        {
            printf("%i < %i < %i", n3, n2, n1); //and prints this if yes
        }
        else    //else it means what this line is printing.
        {
            printf("%i < %i < %i", n2, n3, n1);
        }
    }
    else if (n2 > n1 && n2 > n3)    //Same as above, but for n2...
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
    else if (n3 > n1 && n3 > n2)    //...and for n3
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

//PS: I don't check if all numbers are equal to each other. I was young and dumb back them (Now I'm just older and still dumb)
