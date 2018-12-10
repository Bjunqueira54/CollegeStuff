#include "Server.h"

Params *params;
Options *options;
int ExitVar = 1;
char** EditLines;

int main(int argc, char** argv)
{
    int mp;
    
    mp = open(MEDIT_DEFAULT_MAIN_PIPE, O_RDONLY | O_NONBLOCK);
    
    if(mp != -1)    //If there wasn't an error opening a main pipe file, that means there was a server already open
    {
        fprintf(stderr, "A server is already running!\n\tEXITING\n");
        exit (EXIT_FAILURE);
    }
    else    //Else create a main pipe
        mkfifo(MEDIT_DEFAULT_MAIN_PIPE, S_IRUSR | S_IWUSR);
    
    pthread_t cmd_thread, cl_ut, cl_stats, mp_thread; //Threads in order: Command reading, Client 2d array updating, Client Statistics sending, Main Pipe Client Validation
    
    return (EXIT_SUCCESS);
}

