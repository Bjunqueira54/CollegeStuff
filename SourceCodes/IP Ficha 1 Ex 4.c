#include <stdio.h>

void main()
{
    float teste1,teste2,exame; //dados de entrada
    float nota1,nota2,notaexame,notafinal; //Resultados Pretendidos

    printf("Nota do teste 1: ");
    scanf("%f",&teste1);

    printf("Nota do teste 2: ");
    scanf("%f",&teste2);

    printf("Nota do exame: ");
    scanf("%f",&exame);

    nota1=teste1*0.1;
    nota2=teste2*0.1;
    notaexame=exame*0.8;
    notafinal=nota1+nota2+notaexame;

    printf("O teste 1 vale %1.2f valores, o teste 2 vale %1.2f valores e o exame vale %2.2f valores \n",nota1,nota2,notaexame);
    printf("A nota final da cadeira e %2.2f valores.",notafinal);
}
