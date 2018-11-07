#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fdpipe[2];

	char buffer[512];

	pipe(fdpipe);

	switch(fork())
	{
		case -1:
			fprintf(stderr, "ERROR %i\n", errno);
			return (EXIT_SUCCESS);
		case 0:
			close(fdpipe[0]);
			write(fdpipe[1], "Ola pai", 8);
			close(fdpipe[1]);
			break;
		default:
			close(fdpipe[1]);
			read(fdpipe[0], buffer, 512);
			close(fdpipe[0]);
			fprintf(stdout, "%s\n", buffer);
	}

	return (EXIT_SUCCESS);
}
