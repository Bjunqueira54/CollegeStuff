/*

In this code we'll the getting 3 int numbers from the user's input and comparing them against each
other trying to find the largest of the 3. Once the largest number is found, it'll be printed to the
terminal with the appropriate message.

*/

#include <stdio.h>

void main()
{
    int numero1, numero2, numero3;

    printf("Numero 1: \n");
    scanf("%i", &numero1);  //scans input into all 3 int variables
    printf("Numero 2: \n");
    scanf("%i", &numero2);
    printf("Numero 3: \n");
    scanf("%i", &numero3);

    if (numero1 > numero2 && numero1 > numero3) // IF CONDITION: tests if "numero1" is the largest number...
    {
        printf("O maior numero e o numero %i", numero1);    //... if it prints it out of screen accordingly
    }
    else if (numero2 > numero1 && numero2 > numero3)    // Now it tests if "numero2" is the largest number...
    {
        printf("O maior numero e o numero %i", numero2);    //... and if it is, prints it out on the screen
    }
    else    //Doesn't need to test anything here, because if it's not 1 or 2, than it has to be 3 (ALTHOUGH I'M NOT VERIFYING IF ALL NUMBERS ARE EQUAL, PLEASE DON'T TEST OUT THAT MAJOR FLAW IN MY CODE PLEZ!!!!!)
    {
        printf("O maior numero e o numero %i", numero3);
    }
}
