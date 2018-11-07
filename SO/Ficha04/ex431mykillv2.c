#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void CatchSignal(int sig, siginfo_t *info, void *extra)
{
	fprintf(stdout, "P2: Sinal recebido!\n");
}

int main(int argc, char **argv)
{
	int pid = 0;
	int signal = 0;
	int value = 0;

	struct sigaction action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &CatchSignal;

	if(argc == 1)
	{
		fprintf(stderr, "Falta de syntaxe\n");
		return EXIT_FAILURE;
	}
	else if(sscanf(argv[1], "%d", &pid) != 1)
	{
		fprintf(stderr, "Erro a ler o PID de destino\n");
		return EXIT_FAILURE;
	}
	union sigval sigv;
	sigv.sival_int = getpid();

	if(sigaction(SIGUSR2, &action, NULL) == -1)
	{
		fprintf(stderr, "Why are you here?\n");
		return EXIT_FAILURE;
	}
	sigqueue(pid, SIGUSR1, sigv);
	pause();
}
