/*============================== ex4.3.1.c ======================================
This example improves the base example to show how an int sent by sigqueue() can be received with sigkill().
==============================================================================*/

#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CatchSignal(int sig, siginfo_t *info, void *extra);

int main(void){
	char name[25]="";

	struct sigaction new_action, old_action;

	/* Set up the structure to specify the new action. */
	/* Prepare it to pass an int between processes */
	new_action.sa_flags = SA_SIGINFO;
	new_action.sa_sigaction = &CatchSignal;

    // Intercept SIGINT
    if (sigaction(SIGINT, &new_action, NULL) == -1) {
        perror("Error: cannot handle SIGINT"); // Should not happen
		return EXIT_FAILURE;
    }


	while(strcmp(name,"exit")!=0) {
		printf("Please enter your name:");
		scanf("%24s", name);
		printf("Hello %s.\n", name);
	}
}


/*============================ CatchSignal =====================================
The operating system will assynchronously pass the current process execution to
this function when the process receives the SIGINT signal.
This is an improved signal handler, prepared to receive extra data (int).
==============================================================================*/

void CatchSignal(int sig, siginfo_t *info, void *extra){
	static int sig_count = 0;

	int int_val = info->si_value.sival_int;
	printf("Signal: %d, value: [%d] \n", sig, int_val);

	printf("\nThis already has ocurred %d times.\n",++sig_count);
	if (sig_count==5) {
		printf("\nOk. I will terminate!\n");
		exit(EXIT_SUCCESS);
	}
}
