#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   /* sleep() */

int main(int argc, char** argv) {
    char buffer[25];          /* 24 chars + \0 */
    /* FAZER -> verificar se N e S foram fornecidos */
    int N,S,i;
	char c='*';
	
	if (argc!=4 || 
		sscanf(argv[1],"%i",&N) !=1 ||
		sscanf(argv[2],"%i",&S) !=1 ||
	    sscanf(argv[3],"%c",&c) !=1) {
		printf("Síntaxe: %s Number_Of_Char_To_Print Number_Of_Seconds_to_Wait_Between_Each_Char Char_To_Print", argv[0]);
		return (EXIT_FAILURE);
	}
    
    setbuf(stdout, NULL);  /* Força output printf a aparecer imediatamente */
    printf("\nExercicio 3.03\n");
    for (int i=0; i< N; i++) {
        printf("  %c  ",c);
        sleep(S);
    }
    printf("\n(Exercicio 3.03 Done)\n");
    return (EXIT_SUCCESS);
}
