/*

In this code we'll be doing functions. Each function shall calculate the perimeter or area of a zone and 
print the value on the screen accordingly. If the zone has 5 sides or more or an invalid number, the code
will not calculate anything. If it has 3 sides, it'll calculate the perimeter of the triangle, else it'll 
calculate the area of the square.

*/

#include <stdio.h>

void calcPerimetro(float lado, int nLados)  //You can create your own functions to do stuff. Think of them like puzzle pieces
{                                           //You create them to do a very specific job, and then you can keep calling them
    float perimetro;                        //whenever you please. This one creates a new float var for perimeter...

    perimetro=lado*nLados;  //... and since it's just a perimeter, the formula is: nSides * Size

    printf("O perimetro do triangulo e %5.2f",perimetro);   //Prints the result to the screen
}

void calcArea(float lado)
{
    float area;     //Like the perimeter function, creates a new float var for perimeter.

    area=lado*lado; //The formula for square area is: (Size)^2

    printf("A area do quadrado e %5.2f",area);  //Prints info to screen
}

void main()
{
    float lado; //float for sides measurements
    int nLados; //int for number of sides

    printf("Numero de lados: ");    //asks for number of sides
    scanf("%i",&nLados);

    if (nLados==3 || nLados==4) //checks if it's 3 or 4 sides with ||
    {
        printf("Medida dos lados: ");   //if it's within boundaries, asks for sides measurements. (all sides have the same size)
        scanf("%f",&lado);

        if (nLados==3)  //if there's 3 sides...
        {
            printf("Triangulo! \n");
            calcPerimetro(lado,nLados); //Calls the function to calculate perimeter and gives it as parameters the sizes and number of sides (redundant though...)
        }

        else if (nLados==4) //If it has 4 sides...
        {
            printf("Quadrado! \n");
            calcArea(lado); //Calls the area calculator and passes the side's size as a parameter
        }
    }

    else if (nLados==5) // if it has 5 sizes or...
    {
        printf("Pentagono! \n");
    }
    else    //... and invalid number of sides, doesn't do anything.
    {
        printf("Numero de lados invalido. \n");
        main(); //Now that I'm more experienced in coding, I see that this is a massive fuck up. Never recursive call a function
    }           //unless you know what you're doing. Aka.: Don't call main() from within main(), that's a possible recipe for
}               //disaster...
