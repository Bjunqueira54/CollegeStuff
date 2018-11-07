/*============================== ex4.2.c ======================================
This is a basic mental computing game.
==============================================================================*/

#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INIT_TIMEOUT 20
void Abort(char *msg);
void CatchSignal(int sig);

int Timed_Out = 0;

int main(void) {
	int current_timeout = INIT_TIMEOUT;
	int current_mark = 0;
	int fail_counter = 0;

	int factor_a=0, factor_b=0, sum=0;
  	/* Simple "srand()" seed: just use "time()" */
  	unsigned int iseed = (unsigned int)time(NULL);
  	srand (iseed);
	
	/*Ask the OS to call the CatchSignal function when our process receives
	the SIGAALRM signal*/
	if(signal(SIGALRM,CatchSignal) == SIG_ERR) {
		perror ("Unbale to register an handler to catch the SIGALRM signal.");
		return EXIT_FAILURE;
	}
	
	printf("Try to guess the sum of the provided factors within the decreasing time period.\n");
	printf("You will have %d seconds on this turn. Good luck! \n",current_timeout);
	do {
		factor_a = rand() % 100;
		factor_b = rand() % 100;
		printf("Sum: %d + %d =", factor_a, factor_b);
		Timed_Out = 0;
		alarm(current_timeout--);
		scanf("%d", &sum);
		alarm(0);
		if (Timed_Out) {
			fail_counter ++;
			printf("Timeout! No points earned this time. You will have %d seconds on this turn. Good luck! \n",current_timeout);
		} else {
			if (sum != factor_a + factor_b) {
				fail_counter ++;
				printf("Wrong value! %d + %d = %d (not %d as you suggest). You will have %d seconds on this turn. Good luck! \n",
					   factor_a, factor_b, factor_a + factor_b, sum, current_timeout);
			} else {
				current_mark ++;
				printf("Congratulations! Your current mark is %d.\n", current_mark);
			}
		}		
	} while(current_timeout > 0 && fail_counter < 2);
	printf("Game over. You reach the %d/20 mark!\n", current_mark);
}


/*============================ CatchSignal =====================================
The operating system will assynchronously pass the current process execution to
this function when the process receives the SIGALRM signal.
==============================================================================*/
void CatchSignal(int sig){	
	printf("\nTimeout\n!");
	Timed_Out = 1;
}