#include <stdio.h>

float media(float n1, float n2)
{
    float media;

    media=(n1+n2)/2;

    return media;
}

void main()
{
    float n1, n2, med;


    do{
        printf("Test1: ");
        scanf("%f", &n1);

        printf("Teste2: ");
        scanf("%f", &n2);

        med=media(n1,n2);

        if(med>=9.5){
            printf("%5.2f \n", med);
            printf("APROVADO! \n");
        }else{
            printf("%5.2f \n", med);
            printf("REPROVADO! \n");
        }
    } while( n1>=0 && n2>=0 );
}
