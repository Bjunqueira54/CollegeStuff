#include <sys/errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void myabort(const char * msg, int exit_status)
{
	perror(msg);
	exit(exit_status);
}

int main(int argc,char *argv[])
{
	int n,fd[2];
	pid_t pid;

	if(argc!=3)
	{
		fprintf(stderr,"Syntax: %s command1 command2\n",argv[0]);
		return (EXIT_FAILURE);
	}

	if(pipe(fd)<0)
		myabort("Unable to create the unamed pipe",-2);

	switch((pid=fork()))
	{
		case -1: // Error
			myabort("Unable to fork()",-3);
		    break;
		case  0:// Child process (will be used to execute the first command)
			if(close(fd[0])==-1)
				myabort ("CHILD: Error while closing the read end of the pipe.",-4);
			if(close(STDOUT_FILENO)==-1)
				myabort ("CHILD: Error while closing the standard output.",-4);
			if(dup(fd[1])==-1)
				myabort("CHILD: Error while duplicating the pipe write end",-5);
			if(close(fd[1])==-1)
				myabort ("CHILD: Error while closing the original write end descriptor of the pipe.",-4);

			execlp(argv[1],argv[1],NULL);
			myabort ("CHILD: Error while executing first application.",-6);
			break;


		default:// Parent process (will be used to execute the second command)
			if(close(fd[1])==-1)
				myabort ("PARENT: Error while closing the read end of the pipe.",-4);
			if(close(STDIN_FILENO)==-1)
				myabort ("PARENT: Error while closing the standard input.",-4);
			if(dup(fd[0])==-1)
				myabort("PARENT: Error while duplicating the pipe read end",-5);
			if(close(fd[0])==-1)
				myabort ("PARENT: Error while closing the original read end descriptor of the pipe.",-4);

			execlp(argv[2],argv[2],NULL);
			myabort ("PARENT: Error while executing the second application.",-6);
			break;
	}
}
