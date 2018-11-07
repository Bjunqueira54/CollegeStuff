#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CatchSignal(int sig, siginfo_t *info, void *extra)
{
	fprintf(stdout, "P1: Catched signal\n");
	pid_t p = info->si_value.sival_int;
	kill(p, SIGUSR2);
}

int main()
{
	struct sigaction action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &CatchSignal;
	if(sigaction(SIGUSR1, &action, NULL) == -1)
	{
		fprintf(stderr, "Why are you here?\n");
		return EXIT_FAILURE;
	}
	char input[25] ="";

	while(strcmp(input, "exit") != 0)
	{
		fprintf(stdout, "Escreva: ");
		fscanf(stdin, "%25s", input);
	}
}
