#include <stdio.h>
#include "imprime.h"

int main(int argc, char** argv)
{
	if(argc <= 1)
	{
		fprintf(stderr, "Erro de syntax: aula02 'STRING HERE'\n");
		return -1;
	}

	if(argc > 2)
	{
		fprintf(stderr, "So aceito 2 argumentos\n");
		return -1;
	}

	imprime(argv[1]);

	return 0;
}
