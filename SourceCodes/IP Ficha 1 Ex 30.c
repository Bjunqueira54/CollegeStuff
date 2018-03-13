#include <stdio.h>
#define TAXA_A 1.052
#define TAXA_B 1.018

void main()
{
    int popA, popB, anos;

    popA=500;
    popB=1500;
    anos=0;

    do
    {
        popA=popA*TAXA_A;
        popB=popB*TAXA_B;
        anos=anos+1;
    }
    while(popA <= popB);

    printf("A Populacao A ultrapassa a populacao B ao fim de %i anos.", anos);
}
