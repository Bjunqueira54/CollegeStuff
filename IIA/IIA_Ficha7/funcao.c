#include "funcao.h"

// Calcula a qualidade de uma solucao
// Parametros de entrada: Solucao actual, a, Matriz de adjacencias, mat, Numero de vertices, vert
// Parametros de saida: Custo, total - Neste caso, e o numero de ligacoes que existem entre os vertices dos dois grupos
int calcula_fit(int a[], int *mat, int vert)
{
	int total = 0;
	int i, j;

	for (i = 0; i < vert; i++)
		if (a[i] == 0)
		{
			for (j = 0; j < vert; j++)
				if (a[j] == 1 && *(mat+i*vert+j) == 1)
				    total++;
		}
	return total;
}
