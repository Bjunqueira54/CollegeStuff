#include <stdio.h>
#include <stdlib.h>
#include <string.h>   /* strcmp() */
#include <unistd.h>   /* exec... */
 #include <sys/types.h>
#include <sys/wait.h>

/* pode (ou não) haver código nas partes com ??? */
/* este código é apenas uma sugestão e pode ter uma estrutura diferente */

int main(int argc, char** argv) {
    char palavra[25];          /* 24 chars + \0 */
	int status = 0;
    /* ??? */
	
    setbuf(stdout, NULL);  /* Força output printf a aparecer imediatamente */
    printf("\nExercicio 3.04");
    printf("\nIntroduza o programa a executar\n");
    scanf("%24s", palavra);   /* max = 24 chars */
    
	if (fork() == 0){
		printf("\nFilho: vou executar o comando solicitado.\n");
		execl(palavra, palavra, NULL);
		printf ("Erro no exec()!!! A família de funções exec() apenas retorna se algum erro tiver ocorrido! De outra forma esta e as seguintes linhas de código nunca seriam executadas pois o código e dados associados ao presente processo são substituídos pelo conteúdo do novo programa invocado!");
		perror ("Erro reportado pelo sistema:");
		return EXIT_FAILURE;			
	}
	else {
		printf("\nPai: esperando pela execução do comando solicitado.\n");
		wait(&status);
		printf("\nPai: processo filho terminou.\n");
	}
    /* ??? */    
	

}