/*

In this code we ask for a product price and print out it's final value with Tax included.

*/

#include <stdio.h>

#define ESSENCIAL 1.05  //Multiple defines so later in the code I don't have to keep writting it.
#define LUXO 1.3        //Also is good practice to define a value that you'll use multiple in your code.
#define RESTANTES 1.2   //For example: you use the value "20" in many cases, but later you want to change it. With defines you 
                        //just have to change it once, else you'd have to find all places in your code and change it manually
void main()
{
    float valorArtigo, valorArtigoIVA;  //float variables, to calculate tax values with decimal cases
    int tipoArtigo;

    printf("Qual o valor do artigo?: ");    //Basic asking for input and scanning input.
    scanf("%f", &valorArtigo);
    printf("\n");   // \n is a character that means NewLine in the terminal window

    printf("Qual o tipo de artigo?: \n"     //This is a basic terminal menu. Notice how I could have used multiple printfs
           "1 - Essencial \n"               //but instead I used a single, long lined printf for my ease of coding.
           "2 - Luxo \n"                    //This could've been written in a single line and not spaced like this...
           "3 - Restantes \n");             //but who likes to read code like that?
    scanf("%i", &tipoArtigo);   //gets the users menu choice.
    printf("\n");

    if (tipoArtigo == 1)    //If choice was 1...
    {
        valorArtigoIVA=valorArtigo*ESSENCIAL;   //Calculates the products final price: Products Price * Tax Value (1.05)
        printf("O valor com IVA do artigo e %5.2f Euros", valorArtigoIVA);  //the %5.2f means: scan a float with 2 decimal cases and 5 integer cases. Example: 12345.12
    }
    else if (tipoArtigo == 2)   //If choice was 2...
    {
        valorArtigoIVA=valorArtigo*LUXO;    //Calculates: Product Price * Tax Value (1.3)
        printf("O valor com IVA do artigo e %5.2f Euros", valorArtigoIVA);
    }
    else
    {
        valorArtigoIVA=valorArtigo*RESTANTES;   //Calculates: ProductPrice * TaxValue (1.2)
        printf("O valor com IVA do artigo e %5.2f Euros", valorArtigoIVA);
    }
}
