#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

//WRITER
int main(int argc, char** argv)
{
    int fd = open("/tmp/reading_pipe", O_WRONLY);
    
    if(fd == -1)
    {
        fprintf(stderr, "Error opening pipe\n");
        exit (EXIT_FAILURE);
    }
    
    fprintf(stdout, "Enter reader pid: ");
    pid_t reader_pid;
    fscanf(stdin, "%d", &reader_pid);
    
    kill(reader_pid, SIGUSR1);
    getchar();
    
    while(1)
    {
        char sentence[50];
        
        /*fprintf(stdout, "Write your sentence: ");
        fflush(stdin);
        fgets(sentence, 50, stdin);*/
        
        //sentence[strlen(sentence) - 1] = '\0';
        
        fprintf(stdout, "I shall now send a pre-write sentence\n");
        
        fprintf(stdout, "Press enter to send it...");
        
        getchar();
        
        strcpy(sentence, "Hello Son\0");
        
        write(fd, sentence, strlen(sentence));
        
        memset(sentence, 0, 50 * sizeof(char));
        
        strcpy(sentence, "Hello Father\0");
        
        write(fd, sentence, strlen(sentence));
        
        if(strcmp(sentence, "exit") == 0)
        {
            exit (EXIT_SUCCESS);
        }
    }
    
    return (EXIT_SUCCESS);
}