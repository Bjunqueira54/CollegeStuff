#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 1024

void Abort(char* msg)
{
 fprintf(stderr, "%s", msg);
 exit (EXIT_FAILURE);
}

int main(int argc, char** argv)
{
 int fd, clpid, pipenumber;
 char msg[BUFFERSIZE];
 char pipename[25];
 char cl_pid[10];

 fprintf(stdout, "Pipe number: pipe");
 fscanf(stdin, "%i", &pipenumber);
 sprintf(pipename, "pipe%i", pipenumber);
 getchar();

 mkfifo(pipename, S_IRUSR | S_IWUSR);

 fprintf(stdout, "Client PID: ");
 fgets(cl_pid, 10, stdin);
 sscanf(cl_pid, "%d", &clpid);

 union sigval sig_value;
 sig_value.sival_int = pipenumber;

 fprintf(stdout, "Message to send: ");
 fgets(msg, BUFFERSIZE, stdin);

 if(sigqueue(clpid, SIGUSR1, sig_value) == -1)
 {
  Abort("Error on sigqueue()");
 }
 printf("\n Signal <%i> and <%d> value successfully sent to process <%d>.\n", SIGUSR1, pipenumber, clpid);

 fd = open(pipename, O_WRONLY);

 write(fd, msg, strlen(msg)+1);
 close(fd);

 return (EXIT_SUCCESS);
}
