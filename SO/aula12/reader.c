#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <limits.h>
#include <pthread.h>




#define BUFFSIZE PIPE_BUF


void myabort(const char * msg, int exit_status){
	perror(msg);
	exit(exit_status);
}


void * reader_thread(void * fd) {
	int nr=0;
	char buff [BUFFSIZE];

	while((nr=read(*(int *)fd,buff,BUFFSIZE-1))>0){
		buff[nr]='\0';
		printf("mypipe[%d]:\n%s", *(int *)fd, buff);
	}
	if(nr==-1) *(int *)fd=errno;
	return fd;
}


int main () {

	int fd1=0,fd2=0,nr=0;
	int fd1_bk,fd2_bk;
	int * t1_ret, *t2_ret;

	pthread_t t1, t2;


	if((fd1 = open("mypipe1", O_RDWR))==-1) myabort("Error on open()! pipe1",-1);
	if((fd2 = open("mypipe2", O_RDWR))==-1) myabort("Error on open()! pipe2",-1);
	fd1_bk = fd1;
	fd2_bk = fd2;

	if(pthread_create(&t1, NULL,reader_thread,(void *)&fd1)!=0)
		myabort("Error on PTHREAD_CREATE t1",-2);
	if(pthread_create(&t2, NULL,reader_thread,(void *)&fd2)!=0)
		myabort("Error on PTHREAD_CREATE t2",-2);

	if(pthread_join(t1, (void *)&t1_ret)!=0) 
		myabort("Error on PTHREAD_JOIN t1",-3);
	if(pthread_join(t2, (void *)&t2_ret)!=0) 
		myabort("Error on PTHREAD_JOIN t2",-3);


	printf("Thread t1 returns <%d>.\n",*t1_ret);
	printf("Thread t2 returns <%d>.\n",*t2_ret);

	if(close(fd1)==-1) myabort("Error on close() fd2!",-4);
	if(close(fd2)==-1) myabort("Error on close() fd2!",-4);
	return EXIT_SUCCESS;
}
