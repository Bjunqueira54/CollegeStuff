/*
cc -g ex6.1.1.c -pthread -o ex6.1.1

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

//This variable is global so that the main thread and the created ones 
//can access it concurrently.
int exit_threads;

void * thread_main_function(void * ptr){
	int seconds, i;
    char * character = (char *) ptr;
    
    while (!exit_threads){
	    seconds = rand() % 5 + 1;

	    for (i = 0; i < seconds; i++){
    		sleep(1);
    		printf(".");
	    }

	    for (i = 0; i < 3; i++){
    		sleep(1);
    		printf("%s", character);
	    }
    }

    return NULL;
}


int main() {
	pthread_t thread1, thread2;
	char buffer[1024];

	setbuf(stdout, NULL); //no buffering
	srand(time(NULL)); //initialize random generator
	exit_threads = 0; //flag threads to stay running

	//attr=NULL => the thread is created with default attributes
	if (pthread_create(&thread1, NULL, thread_main_function, (void *) "A") != 0)
		Abort("Error creating thread 1.");

	if (pthread_create(&thread2, NULL, thread_main_function, (void *) "B") != 0)
		Abort("Error creating thread 2.");
    
    while (1) {
		scanf(" %1023[^\n]s", buffer);
		printf("User: %s\n", buffer);

		if (strcmp(buffer, "exit") == 0)
			break;
    }

    exit_threads = 1;

	//wait the running threads terminate
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nBye!\n");

    return 0;
}