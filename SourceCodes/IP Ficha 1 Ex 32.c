/*

This code takes a integer number and adds it's digits together. For example: Number 123=6 -> 1+2+3 = 6

*/

#include <stdio.h>

void main()
{
    int n, soma;

    printf("Introduza um numero inteiro: ");    //Gets number from user
    scanf("%10i", &n);

    soma=0; //The results starts at 0

    while(n>0)  //This next parts requires a bit of explanation
    {
        soma=soma+(n%10);   //Here we do "soma" (result) is equal to itself + the module of n with 10. As seen before, module of a number with another number is basically a non-decimal division where the leftover is returned to us. in this case it would be 123 / 10 = 12.3 but 123 % 10 = 3
        n=n/10;             //Then we divide n. Since n is an int, instead of become 12.3 it becomes 12 because it's don't round nor store the decimal.
    }                       //And then repeats this cycle until n<=0. Since we're always dividing by 10, it'll eventually become exactly 0

    printf("A soma dos digitos e %d", soma);
}
