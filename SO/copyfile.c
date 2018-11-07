#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define PERM (S_IRUSR | S_IWUSR)
#define BUFFERSIZE 1024

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		fprintf(stderr, "Sintaxe Errada. /copyfile FicheiroA FicheiroB\n");
		return (EXIT_FAILURE);
	}

	int fa, fb;

	fa = open(argv[1], O_RDONLY);

	if(fa == -1)
	{
		fprintf(stderr, "Erro abrir o ficheiro A. ERRO %i\n", errno);
		close(fa);
		return (EXIT_FAILURE);
	}

	fb = open(argv[2], O_WRONLY|O_CREAT|O_EXCL, PERM);

	if(fb == -1)
	{
		fprintf(stderr, "Erro abrir o ficheiro B. ERRO %i\n", errno);
		close(fb);
		return (EXIT_FAILURE);
	}

	char buffer[BUFFERSIZE];

	return (EXIT_SUCCESS);
}
