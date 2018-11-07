/*============================== ex4.1.c ======================================
This example shows how the current process can ask the operating system to 
call a given local handler (i.e. function) to deal with the reception of a
given signal. In this case the received signal will be SIGINT and it will be
triggered by entering the ^C character sequence at the process input.

When the programmer does not specify an handler the operating system provides
a default behavior. For SIGINT the process is killed.
==============================================================================*/

#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Abort(char *msg);
void CatchSignal(int sig);

int main(void){
	char name[25]="";
	
	/*Ask the OS to call the CatchSignal function when our process receives
	the SIGINT signal*/
	if(signal(SIGINT,CatchSignal) == SIG_ERR) {
		perror ("Unbale to register an handler to catch the SIGINT signal.");
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
==============================================================================*/
void CatchSignal(int sig){
	static int sig_count = 0;
	
	printf("\nI just received the signal %d.",sig);
	printf("\nThis already has ocurred %d times.\n",++sig_count);
	if (sig_count==5) {
		printf("\nOk. I will terminate!\n");
		exit(EXIT_SUCCESS);
	}
}