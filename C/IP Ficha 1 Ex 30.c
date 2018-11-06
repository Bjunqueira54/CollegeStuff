/*

This code is used to calculate after how many years Population A grows larger than Pop B

*/

#include <stdio.h>

#define TAXA_A 1.052    //These defines are growth rate. 1.052 = 5.2%
#define TAXA_B 1.018

void main()
{
    int popA, popB, anos;

    popA=500;   //Innitial values for PopA\B and years
    popB=1500;
    anos=0;

    do  //CICLES! Keep repeating the following instructions...
    {
        popA=popA*TAXA_A;
        popB=popB*TAXA_B;
        anos=anos+1; //this could be replaced with "anos++;" but I was yound and stupid back then ¯\_(ツ)_/¯
    }
    while(popA <= popB);    //... until Pop A is larger than Pop B

    printf("A Populacao A ultrapassa a populacao B ao fim de %i anos.", anos); //Prints years to terminal
}
