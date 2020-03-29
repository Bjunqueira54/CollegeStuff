//cc -o ex6.1.3.nproc ex6.1.3.nproc.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   	// exec()
#include <sys/types.h>  // wait()
#include <sys/wait.h>


#define  MAX_PROCESSES	10

int main(int argc, char** argv) {
	int pidv[MAX_PROCESSES];
	int i;
	int n_cmd_instances = 0; //number of parallel instances to launch
	char * cmd = NULL;

	if (argc!=3 || sscanf(argv[1],"%u",&n_cmd_instances)!=1 
            || n_cmd_instances > MAX_PROCESSES ) {
		fprintf( stderr,"Syntax: %s n command (launch n<%d simultaneous instances of command cmd.)\n", MAX_PROCESSES, argv[0]);
		return EXIT_FAILURE;
	}

	cmd = argv[2];
	printf("Running %d instances of the comand <%s> ... \n",n_cmd_instances,cmd);
	
	for (i=0; i < n_cmd_instances; i ++) {
		switch ((pidv[i]=fork())) {
			case -1:
				perror("fork()");
				return EXIT_FAILURE;
				break;
			case 0:
				execlp(cmd,cmd,NULL);
				break;
			default:
				continue;
		}
	}
	printf("Instances successfully launched. Waiting their conclusion...\n");
	for (i=0; i < n_cmd_instances; i++) wait(NULL);

	printf("\nAll instances termiate. See you!\n");
	return EXIT_SUCCESS;
}
