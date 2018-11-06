#include <stdio.h>

#define N_ALUNOS 12
#define N_AULAS 50
#define MAX_FALTAS 0.25

void main()
{
    float nota1, nota2, notaAluno, pFaltas, somaNotas, media, faltas;
    int i, nReprovados, nAprovados;

    nReprovados = 0;
    nAprovados = 0;
    somaNotas=0;

    for(i=0;i<N_ALUNOS;i++)
    {
        printf("Introduza o numero de faltas do Aluno: ");
        scanf("%f", &faltas);

        pFaltas = faltas / N_AULAS;

        if(pFaltas > MAX_FALTAS)
        {
            printf("Aluno Reprovado! \n");
            nReprovados = nReprovados + 1;
        }
        else
        {
            printf("Introduza Nota 1: "),
            scanf("%f", &nota1);

            printf("Introduza Nota 2: ");
            scanf("%f", &nota2);

            notaAluno = (nota1 + nota2)/2;
            nAprovados = nAprovados + 1;
            somaNotas=somaNotas+notaAluno;
        }
    }

    media=somaNotas/nAprovados;

    printf("Numero de Alunos Reprovados: %i \n", nReprovados);
    printf("Numero de Alunos Aprovados: %i \n", nAprovados);
    printf("Media das notas dos alunos aprovados: %f \n", media);
}
