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
    
    char main_pipe[101];
    pthread_t cmd_thread, cl_ut, cl_stats, mp_thread; //Threads in order: Command reading, Client 2d array updating, Client Statistics sending, Main Pipe Client Validation
    struct sigaction cl_disc, cl_sig;
    
    cl_disc.sa_flags = SA_SIGINFO;
    cl_disc.sa_sigaction = &ClientDisconnect;

    cl_sig.sa_flags = SA_SIGINFO;
    cl_sig.sa_sigaction = &ClientSignals;
    
    sigaction(SIGUSR1, &cl_disc, NULL);
    sigaction(SIGUSR2, &cl_sig, NULL);
    
    if(argc != 1)
    {
        params = malloc(sizeof(Params));
        params->f = 0;
        params->n = 0;
        params->p = 0;
        char c;
        while( (c = getopt(argc, argv, "f:n:p:")) != -1 )
        {
            switch(c)
            {
                case 'f':   //Database File command line argument
                    params->f = 1;
                    params->fname = optarg;
                    break;
                case 'p':   //Main Pipe  command line argument
                    params->p = 1;
                    params->pipename = optarg;
                    sprintf(main_pipe, "/tmp/%s", params->pipename);
                    mkfifo(main_pipe, S_IRUSR | S_IWUSR);
                    break;
                case 'n':   //Number of client named pipes argument
                    fprintf(stderr, "No idea how to use this for now\n");
                    break;
                default:
                    fprintf(stderr, "Unknown parameter -%c!\n", c);
            }
        }
    }
    
    if(params->f != 1)
        params->fname = DEFAULT_DB_FILE;
        
    FILE *db = fopen(params->fname, "rt");
    if(db == NULL)
        db = fopen(params->fname, "wt");
    fclose(db);
    
    if(params->p != 1)
    {
        strcpy(main_pipe, MEDIT_DEFAULT_MAIN_PIPE);
    }
    
    options = malloc(sizeof(Options));
    
    ParseEnvVars(options);
    
    EditLines = malloc(options->lines * sizeof(char*));
    
    if(EditLines == NULL)
    {
        fprintf(stderr, "Error allocating memory of the 2D array\n");
        exit (EXIT_FAILURE);
    }
    
    for(int i=0; i<options->lines; i++)
    {
        EditLines[i] = malloc(options->columns * sizeof(char));
        
        if(EditLines[i] == NULL)
        {
            fprintf(stderr, "Error allocating memory for line %i of the 2D array\n", i);
            exit (EXIT_FAILURE);
        }
    }
    
    do
    {
        pthread_create(&cmd_thread, NULL, ParseCommands, NULL);
        pthread_join(cmd_thread, NULL);
    }
    while(ExitVar != 1);
    
    return (EXIT_SUCCESS);
}