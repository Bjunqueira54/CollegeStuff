/*============================== ex4.3.mykill.c ======================================
This example shows how to use sigqueue() to send a signal to given process.
==============================================================================*/

#include <signal.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	int pid = 0;
	int signal = 0;
	char name[25]="";

	/*
	   union sigval {
		   int   sival_int;
		   void *sival_ptr;
	   };
	*/
	union sigval sig_value;
	
	
	//Syntax checking & command line arguments parsing
	if (argc!=3 ||
		sscanf(argv[1],"%d",&pid)!=1 ||
		sscanf(argv[2],"%d",&signal)!=1) {
		printf("\nSyntax: %s PID SIGNAL_NUMBER\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	/* 
	With sigqueue()/sigaction() we can communicate an int between processes.
	This however must not be used as a inter process communication mechanism.
	If the receiving process has installed a handler for this signal
	using the SA_SIGINFO flag to sigaction(2), then it can obtain this
	data via the si_value field of the siginfo_t structure passed as the
	second argument to the handler.  Furthermore, the si_code field of
	that structure will be set to SI_QUEUE.	  	  
	*/
	sig_value.sival_int = 100;	
	
	if(sigqueue(pid,signal,sig_value) == -1){
        perror("sigqueue() error");
        return (EXIT_FAILURE);
    }
	
	printf("\n Signal <%d> successfully sent to process <%d>.\n", signal, pid);
	return(EXIT_SUCCESS);
}
