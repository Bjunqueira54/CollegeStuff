#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFERSIZE 1024

void Abort(char* msg);

void main()
{
	fd_set conj_fd_read, conj_fd_read_temp;
	int fd1, fd2;
	int nr=0;
	char buffer[BUFFERSIZE];

	if( (fd1=open("mypipe1", O_RDONLY | O_NONBLOCK)) == -1 || (fd2=open("mypipe2", O_RDONLY | O_NONBLOCK)) == -1)
		Abort("open");

	FD_ZERO(&conj_fd_read);
	FD_SET(fd1, &conj_fd_read);
	FD_SET(fd2, &conj_fd_read);

	while(1)
	{
		conj_fd_read_temp = conj_fd_read;

		switch(select(32, &conj_fd_read_temp, NULL, NULL, NULL))
		{
			case -1:
				if(errno == EINTR)
					continue;
				else
					Abort("Select");
				break;
			case 0:
				fprintf(stdout, "Timeout...\n");
				continue;
			default:
				if(FD_ISSET(fd1, &conj_fd_read_temp))
				{
					while((nr=read(fd1, buffer, BUFFERSIZE-1)))
					{
						buffer[nr]=0;
						fprintf(stdout, "MyPipe1=<%s>\n", buffer);
					}
				}
				else if(FD_ISSET(fd2, &conj_fd_read_temp))
				{
					while((nr=read(fd2, buffer, BUFFERSIZE-1)))
					{
						buffer[nr]=0;
						fprintf(stdout, "MyPipe2=<%s>\n", buffer);
					}
				}
		}
	}
	exit (EXIT_SUCCESS);
}

void Abort(char* msg)
{
	fprintf(stderr, "ERROR: %s\n", msg);
	abort();
}
