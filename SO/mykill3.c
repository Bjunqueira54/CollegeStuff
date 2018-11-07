#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc < 4)
	{
		fprintf(stderr, "Erro de syntaxe: ./mykill3 PID SIGNAL MSG");
		return (EXIT_FAILURE);
	}

	int pid;
	sscanf(argv[1], "%i", &pid);
	int sig_num;
	sscanf(argv[2], "%i", &sig_num);

	union sigval sig_value;

	sig_value.sival_ptr = argv[4];
	if(sigqueue(pid, sig_num, sig_value) == -1)
	{
		fprintf(stderr, "Erro!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
