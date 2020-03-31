/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
    pid_t child_pid;
    int fd_in[2], fd_out[2];
    char * msg = "teste";    
    char resposta[50] = { 0 };
    int num;
    
    pipe(fd_in); // filho pra pai
    pipe(fd_out); // pai para filho
    
    child_pid = fork();
    
    
    if(child_pid == 0)    //child
    {
        //THIS WORKS
        close(fd_in[0]);
        close(fd_out[1]);
        num = read(fd_out[0],resposta,49);
        printf("FILHO: %s\n", resposta);
        
        printf("Resposta para o pai: ");
        fgets(resposta, 50, stdin);
        
        resposta[strlen(resposta) - 1] = '\0';
        
        write(fd_in[1], resposta, strlen(resposta));
    }
    else    //father
    {
        //THIS WORKS!
        close(fd_in[1]); // escrita off
        close(fd_out[0]); // leitura off
        
        write(fd_out[1], msg, strlen(msg)); //escreve "teste" para o filho
        
        read(fd_in[0], resposta, 49);  // 6 fixo para atamancar o teste
        printf("\nrecebi [%s]\n",resposta);
    }
    
    if(child_pid != 0)
    {
        write(fd_out[1], msg, strlen(msg)); //escreve "teste" para o filho
        
        read(fd_in[0], resposta, 49);  // 6 fixo para atamancar o teste
        printf("\nrecebi [%s]\n",resposta);
    }
    else
    {
        num = read(fd_out[0],resposta,49);
        printf("FILHO: %s\n", resposta);
        
        printf("Resposta para o pai: ");
        fgets(resposta, 50, stdin);
        
        resposta[strlen(resposta) - 1] = '\0';
        
        write(fd_in[1], resposta, strlen(resposta));
    }
    
    exit(0);
}*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    int	outfd[2];
    int	infd[2];

    /* set usr/host/remote_path/local_path to something meaningful */

    /* create pipes for stdin/out to dup in the child */	

    pipe(outfd); /* Where the parent is going to write to */
    pipe(infd); /* From where parent is going to read */

    pid_t child_pid = fork();

    if(!child_pid)
    {
        /* child, close stdin/out and use parent pipes instead */

        /*close(STDOUT_FILENO);
        close(STDIN_FILENO);

        dup2(outfd[0], STDIN_FILENO);
        dup2(infd[1], STDOUT_FILENO);*/

        /* close all pipe ends, needed end has been dup'd other end
             is not needed */

        close(outfd[0]);
        //close(outfd[1]);
        close(infd[0]);
        //close(infd[1]);
    }
    else /* parent */
    {
        close(outfd[1]); /* These are being used by the child */
        close(infd[1]);
    }

    if(child_pid != 0)  /*FATHER*/
    {
        printf("I am the father!\n");
        printf("Send a Message to my son: ");
        fgets(message, sizeof(char) * 100, stdin);
        printf("FATHER: Your message is - %s\n", message);
        //message[strlen(message) - 1] = '\0';
        write(outfd[1], message, strlen(message));
        
        sleep(2);
        
        memset(message, 0, 100);
        
        while(read(infd[0], message, sizeof(char) * 100) != 0);
        
        printf("FATHER: %s\n", message);
    }
    else    /*CHILD*/
    {
        while(read(outfd[1], message, sizeof(char) * 100) != 0);
        
        int msglength = strlen(message);
        
        message[msglength - 1] = ' ';
        message[msglength] = '1';
        message[msglength + 1] = '2';
        message[msglength + 2] = '3';
        message[msglength + 3] = '4';
        message[msglength + 4] = '\0';
        
        write(infd[1], message, strlen(message));
    }

    close(outfd[1]);
    close(infd[0]);
}