/*

This algorithm checks if the input number is prime or not. (fun...)

*/

#include <stdio.h>

int divisores(int n)    //A int function that will return an int.
{   //The parameter is int n, the number that will be given to this function upon being called and the number that is being tested if it's prime or not
    int i, div, resto;

    div=0; //Our counter for divisions. This is what will determine if n is prime or not.

    for(i=1;i<=n;i++)   //i=1; while i doesn't reach n; increment i
    {
        resto=n%i;  //Ah module! My nemesis...

        if(resto==0)    //If module returns a 0, that means the division didn't produce a decimal number...
        {
            div++;  //... meaning that whatever i is it can divide with n, which means this counter gets incremented
        }
    }

    return div; //returns how many times n was successfully divided
}

void main()
{
    int num, div;

    do
    {
        printf("Introduza um numero: ");    //Gets the number to test
        scanf("%i", &num);

        div=divisores(num); //sends it to the function above and them div is equal to whatever it returns

        if(div==2)  //if the number was only successful divided twice (with 1 and with itself)...
        {
            printf("NUMERO PRIMO! \n"); //... that means the number is prime.
        }
    }
    while(num>0);   //keeps repeating this operation until user inputs 0 or a negative number. (SEE!? No more of that main() inside main() bullshit anymore)
}
