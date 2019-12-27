/*
This exercise is based on the 6.1 exercise with the following improvements:
 - the user have direct control over which thread to work 
 - threads should not produce output while any other is working

cc -g ex6.1.1.c -pthread -o ex6.1.1

Author: Luís Santos

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>


//The simple way to initialize mutex and cond. var.
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

//In this exercise we illustrte another approach
pthread_mutex_t mutex;
pthread_cond_t cv;


void Abort(char * message){
	fprintf(stderr,"%s\n", message);
	exit(EXIT_FAILURE);
}

//This variable (Thread STATE) is global so that the main thread and the worker threads
//can access it concurrently.
// X : both threads must terminate
// W : means thread must keep waiting
// A : means thread A must run
// B : means thread B must run

char tstate = 'W'; 

void * thread_main_function(void * ptr){
	int seconds, i;
    char character = *((char *) ptr);

    //printf("Worker thread %c alive.\n",character);
    	
    do{    	
    	pthread_mutex_lock(&mutex);
    	printf("\nWorker thread %c successfully locks the mutex.\n",character);
	    /* Remember that cond_wait unlocks the mutex before blocking (waiting)! */
	    /* After unlocking, other threads can claim the mutex. */
	    /* When this thread is later woken it will */    	
	    /* re-lock the mutex before returning */

		while (tstate != 'X' && tstate != character) {
			printf("\nWorker thread %c cond_wait.\n",character);
			pthread_cond_wait(&cv, &mutex);
		}
		if (tstate == 'X') break;

		//tstate == character
	    seconds = rand() % 5 + 1;
	    for (i = 0; i < seconds; i++){
    		sleep(1);
    		printf(".");
	    }
	    for (i = 0; i < 3; i++){
    		sleep(1);
    		printf("%c", character);
	    }

	    tstate = 'W';
	    printf("\nWorker thread %c cond_broadcast.\n",character);
	    pthread_cond_broadcast(&cv);
		pthread_mutex_unlock(&mutex);
		printf("\nWorker thread %c unlocks the mutex.\n",character);
		printf("\nWorker thread %c locking the mutex.\n",character);
	} while (1);

	printf("\nWorker thread %c unlocks the mutex.\n",character);
    pthread_mutex_unlock(&mutex);
	printf("\nWorker thread %c terminating.\n",character);
    return NULL;
}


int main() {
	pthread_t thread1, thread2;
	char buffer[1024];

	setbuf(stdout, NULL); //no buffering
	srand(time(NULL)); //initialize random generator
	tstate = 'W'; //flag threads to stay waiting for user input

	// Inicialização
	pthread_cond_init(&cv, NULL);
	pthread_mutex_init(&mutex, NULL);
	printf("\nMain thread locking.\n");
	

	//attr=NULL => the thread is created with default attributes
	if (pthread_create(&thread1, NULL, thread_main_function, (void *) "A") != 0)
		Abort("Error creating thread 1.");

	if (pthread_create(&thread2, NULL, thread_main_function, (void *) "B") != 0)
		Abort("Error creating thread 2.");
    
    while (1) {
    	printf("\nMain thread locking the mutex.\n");
    	pthread_mutex_lock(&mutex);
    	printf("\nMain thread successfully lock the mutex.\n");
    	printf("\nMain thread cond_wait.\n");
		while (tstate != 'W') {
			printf("\nMain thread cond_wait.\n");
			pthread_cond_wait(&cv, &mutex);
		}
    	
    	printf("\nUser input please (A: Thread A: Thread B; X: eXit):");
		scanf(" %1023[^\n]s", buffer);

		if (strcasecmp(buffer, "A") == 0 || 
		  	  strcasecmp(buffer, "B") == 0 ||
			  strcasecmp(buffer, "X") == 0) {
		    tstate = toupper(buffer[0]);
		    printf("\nMain thread cond_broadcast.\n");
		    pthread_cond_broadcast(&cv);
		    if (tstate == 'X') break;			
		} else {
			tstate = 'W';
		}
		pthread_mutex_unlock(&mutex);
		printf("\nMain thread unlocks the mutex.\n");

    }
    pthread_mutex_unlock(&mutex);
    printf("Waiting for threads to terminate!\n");
    
	//wait the running threads terminate
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_cond_destroy(&cv);

    printf("\nBye!\n");

    return 0;
}
