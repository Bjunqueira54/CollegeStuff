#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

//READER

int fd;
void DeletePipe(int sig);

void ReadFromPipe(int sig)
{
    fprintf(stdout, "Entering Reading Mode\n");
    
    while(1)
    {
        char sentence[50];
        
        read(fd, sentence, 50 * sizeof(char));
        
        fprintf(stdout, "The sentence: %s\n", sentence);
        
        if(strcmp(sentence, "exit") == 0)
        {
            DeletePipe(0);
            exit (EXIT_SUCCESS);
        }
        
        memset(sentence, 0, sizeof(char) * 50);
    }
    
    exit (EXIT_SUCCESS);
}

void DeletePipe(int sig)
{
    system("rm /tmp/reading_pipe");
}

int main(int argc, char** argv)
{
    signal(SIGUSR1, ReadFromPipe);
    signal(SIGPIPE, DeletePipe);
    
    mkfifo("/tmp/reading_pipe", 0600);
    
    fprintf(stdout, "Waiting for pipe to be opened...\n");
    
    fd = open("/tmp/reading_pipe", O_RDONLY);
    
    if(fd == -1)
    {
        fprintf(stderr, "Error opening pipe\n");
        exit (EXIT_FAILURE);
    }
    
    fprintf(stdout, "Pipe opened in fd: %d\n", fd);
    fprintf(stdout, "Entering wait mode\n");
    
    while(1) {}
    
    return (EXIT_SUCCESS);
}
