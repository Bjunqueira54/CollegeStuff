#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 1024

void Abort(char* msg)
{
    fprintf(stdout, "%s", msg);
    abort();
}

void *t_job(void *arg)
{
    fd_set cr, crt;
    int fd = *(int*) arg;
	int n;
	char msg[BUFFERSIZE];

    FD_ZERO(&cr);
    FD_SET(fd, &cr);

    while(1)
    {
        crt = cr;

        switch(select(32, &crt, NULL, NULL, NULL))
        {
            case -1:
				Abort("ERROR select()");
                break;
            case 0:
				Abort("Select TIMEOUT");
                break;
            default:
                if(FD_ISSET(fd, &crt))
				{
					while(n=read(fd, msg, BUFFERSIZE-1))
					{
						msg[n] = 0;
						fprintf(stdout, "FD: %s>", msg);
					}
				}
        }
    }
}

int main(int argc, char** argv)
{
	pthread_t t1, t2;
    int fd1, fd2;

    if(((fd1 = open("mypipe1", O_RDWR)) == -1) || ((fd2 = open("mypipe2", O_RDWR)) == -1))
            Abort("ERROR open()");

    pthread_create(&t1, NULL, t_job,(void *) &fd1);
    pthread_create(&t2, NULL, t_job,(void *) &fd2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return EXIT_SUCCESS;
}
