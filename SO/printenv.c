#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc)
{
	char* env;
	for(int i=1; i<argv; i++)
	{
		env = getenv(argc[i]);
		if(env == NULL)
		{
			fprintf(stdout, "Var %i: Nao Definida!\n", i);
		}
		else
		{
			fprintf(stdout, "Var %i: %s\n", i, getenv(argc[i]));
		}
	}

	return (EXIT_SUCCESS);
}
