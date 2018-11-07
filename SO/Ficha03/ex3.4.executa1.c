#include <stdio.h>
#include <stdlib.h>
#include <string.h>   /* strcmp() */
#include <unistd.h>   /* exec... */

/* pode (ou não) haver código nas partes com ??? */
/* este código é apenas uma sugestão e pode ter uma estrutura diferente */

int main(int argc, char** argv) {
    char palavra[25];          /* 24 chars + \0 */
    /* ??? */
	
    setbuf(stdout, NULL);  /* Cancel buffering (i.e., force immediate output) on standard output */
    printf("\nExercice 3.04");
    printf("\nTell me the program you want to execute:\n");
    scanf("%24s", palavra);   /* max = 24 chars */
    
    /* ??? */
    
    if (strcmp(palavra, "port")==0) {
        /* ??? */
	    execl("port", "port", NULL);
    }
    else
        if (strcmp(palavra, "ingl")==0) {
            /* ??? */
			execl("ingl", "ingl", NULL);
		}
        else {
            fprintf(stderr, "Unknown program ! Try \"port\" or \"ingl\" please.\n");
            return EXIT_FAILURE;
        }
	
    /* ??? */
	fprintf (stderr, "Error on exec() call!!! This line is executed just when the exec call fails. Otherwise the initial process instructions are replaced by the instructions of the (exec)uted program.");
	perror ("Sysrem reported error:");
	return EXIT_FAILURE;
}