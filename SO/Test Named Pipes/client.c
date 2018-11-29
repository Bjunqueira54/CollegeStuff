#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 1024

void Abort(char* msg)
{
 fprintf(stderr, "%s\n", msg);
 exit (EXIT_FAILURE);
}

void OpenReadPipe(char *pipename)
{
 int pipe = open(pipename, O_RDONLY | O_NONBLOCK);
 int bytesread;
 char msg[BUFFERSIZE];

 bytesread = read(pipe, msg, BUFFERSIZE);

 if(bytesread == -1)
 {
  Abort("Error on read()");
 }
 else
 {
  fprintf(stdout, "Pipe had writen: %s\n", msg);
 }
 close(pipe);

 exit (EXIT_SUCCESS);
}

void CatchSignal(int sig, siginfo_t *info, void *extra)
{
 if(sig != SIGUSR1)
 {
  Abort("Wrong signal\n");
 }

 int pipenumber;
 char pipename[25];

 pipenumber = info->si_value.sival_int;

 fprintf(stdout, "si_value.sival_int = %i\n", pipenumber);

 sprintf(pipename, "pipe%i", pipenumber);

 OpenReadPipe(pipename);
}

int main(int argc, char** argv)
{
 int pipe;
 char msg[BUFFERSIZE];

 struct sigaction sigcatcher;

 sigcatcher.sa_flags = SA_SIGINFO;
 sigcatcher.sa_sigaction = &CatchSignal;

 if(sigaction(SIGUSR1, &sigcatcher, NULL) == -1)
 {
  Abort("ERROR IN sigaction()\n");
 }

 fprintf(stdout, "Waiting for server signal...\n");

 while(1);

 return (EXIT_SUCCESS);
}
