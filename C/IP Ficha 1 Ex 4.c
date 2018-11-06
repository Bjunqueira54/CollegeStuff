/*

Algorithm that calculates the average of 2 exams.

*/

#include <stdio.h>

void main()
{
    float teste1,teste2,exame; //dados de entrada. Input Data
    float nota1,nota2,notaexame,notafinal; //Resultados Pretendidos. Output Data

    printf("Nota do teste 1: ");    //Asks for test 1
    scanf("%f",&teste1);

    printf("Nota do teste 2: ");    //Asks for test 2
    scanf("%f",&teste2);

    printf("Nota do exame: ");  //Asks for final exam
    scanf("%f",&exame);

    nota1=teste1*0.1;   //Tests are graded 10% each of the final grade
    nota2=teste2*0.1;
    notaexame=exame*0.8;    //Exam is 80% of the final grade
    notafinal=nota1+nota2+notaexame;    //Final grade is the addition of all tests and the exam (No shit Sherlock! ಠ_ಠ)

    printf("O teste 1 vale %1.2f valores, o teste 2 vale %1.2f valores e o exame vale %2.2f valores \n",nota1,nota2,notaexame); //Prints each individual test and exam after percentage calculations
    printf("A nota final da cadeira e %2.2f valores.",notafinal);   //Prints the final grade.
}
