#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "Falta de argumentos\n");
		return (EXIT_FAILURE);
	}

	kill(atoi(argv[2]), atoi(argv[1]));

	return (EXIT_SUCCESS);
}
