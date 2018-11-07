#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

int main(void)
{
	int n=20;

	signal(SIGALRM,LoseGame);

	do 
	{
	alarm(N);
	N--;
	// ciclo para pedir informação
	printf("A,B");
	scanf(SOMA)


	} while(N-->1);
}

void LoseGame(int signal)
{
	alarm(0);
	printf(" ");
}

