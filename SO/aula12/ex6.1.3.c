/*
cc -g ex6.1.3.c -pthread -o ex6.1.3

Code base: Ricardo Pereira
Minor modifications: Luís Santos

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

void Abort(char * message){
	fprintf(stderr,"%s\n", message);
	exit(EXIT_FAILURE);
}

//These variables iare global so that the main thread and the created ones 
//can access them concurrently.
int exit_threads;
int mypid;

void * thread_main_function(void * ptr){
	int seconds, i, cont=0;
	char * thread_name = (char *) ptr;
    
    while (!exit_threads){
	seconds = rand() % 5 + 1;

	for (i = 0; i < seconds; i++, cont++){
    		sleep(1);
    		printf("[%d:%s:\t%d] {second %d of %d}\n",mypid, thread_name, cont,i,seconds-1);
	}
    }
    return NULL;
}


int main() {
	pthread_t thread1, thread2;
	char buffer[1024];
	int ret = 0;
	
	mypid=getpid();
	setbuf(stdout, NULL); //no buffering
	srand(time(NULL)); //initialize random generator
	exit_threads = 0; //flag threads to stay running

	//attr=NULL => the thread is created with default attributes
	if (pthread_create(&thread1, NULL, thread_main_function, (void *) "Thread A") != 0)
		Abort("Main Thread: Error creating thread A.");

	if (pthread_create(&thread2, NULL, thread_main_function, (void *) "Thread B") != 0)
		Abort("Main Thread: Error creating thread B.");
    
    while (1) {
		ret=scanf(" %1023[^\n]s", buffer);
		if(ret==-1) sleep(1);
		else {
			printf("Main Thread: User: %s\n", buffer);
			if (strcmp(buffer, "exit") == 0) break;
		}
    }

    exit_threads = 1;

    //wait the running threads terminate
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nMain Thread: Bye!\n");

    return 0;
}
