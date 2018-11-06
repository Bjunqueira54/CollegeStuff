/*

This program calculates your "Body Mass Index". Basically it sees if you're fat or not :^)

*/

#include <stdio.h>

float calcIMC(float kg, float mt)   //A float type function. This means after the function is complete, it will return a float value back to main()
{                                   //It takes 2 float parameters, basically it's like you're creating variables, but inside you'll give them a value when you call the function somewhere else
    float imc;  //BMI = "Body Mass Index". This is what will be returned back to main()

    imc=((kg)/(mt*mt)); //Formula is: BMI = Weight / (Height^2)

    printf("IMC: %5.2f \n", imc); //Prints BMI...

    return imc; //... and returns it's value back to main()
}

void main()
{
    int p,i;
    float kg, m, imc;

    printf("introduza o numero de pessoas: ");  //How many people are we testing?
    scanf("%i", &p);

    for(i=1;i<=p;i++)   //This cycle means: i starts at 1; while i is "less than or equal to" the number of people; increase i by 1 each time it's ran successfully before comparing to the middle condition
    {
        printf("Introduza Peso: "); //Person's weight?
        scanf("%f", &kg);

        printf("Introduza Altura: ");   //Person's Height?
        scanf("%f", &m);

        imc=calcIMC(kg, m); //bmi = calcBMI(Weight, Height). After the code above in calcIMC is done running, whatever is in "return imc" is what this imc will be equal to

        if(imc<=18.5)   //Now for all the if\else\else if conditions....
        {
            printf("Abaixo do peso Normal \n"); //Underweight
        }
        else if(imc>18.5 && imc<25)
        {
            printf("Peso Normal \n");   //Healthy
        }
        else if(imc>25 && imc<=30)
        {
            printf("Acima do peso Normal \n"); //Slightly overweight
        }
        else
        {
            printf("Obesidade \n"); //Obese
        }
    }
}
