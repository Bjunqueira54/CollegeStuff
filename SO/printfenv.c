#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envv)
{
	char *a;
	for(int i=1; i<argc; i++)
	{
		a = getenv(argv[i]);

		printf("%s: ",argv[i]);

		if(a == NULL)
			fprintf(stdout,"Variavel Nao Definida\n");
		else
			fprintf(stdout,"%s\n",a);
	}

	return 0;
}
