#include "server.h"

Params *params;
Settings *options;
int ExitVar = 0;

int main(int argc, char** argv)
{
    int mp;
    char processid[19];
    char idnum[8];
    char mpn[25]; //Main Pipe Name
    pid_t pid, self;
    pthread_t cmd_thread, mpipe_thread;
    self = getpid();
    
    /////////////////////////////////////////////////////
    ///Algoritmo para detetar se já existe um servidor///
    /////////////////////////////////////////////////////
    mp = open(MEDIT_DEFAULT_MAIN_PIPE, O_RDONLY | O_NONBLOCK);
    
    if(mp != -1)
    {
        fprintf(stderr, "Server already exists!\nEXITING!\n");
        exit (EXIT_FAILURE);
    }
    else
        mkfifo(MEDIT_DEFAULT_MAIN_PIPE, S_IRUSR | S_IWUSR);

    params = malloc(sizeof(Params));
    params->f = 0;
    params->n = 0;
    params->p = 0;

    char c;

    if(argc != 1)
    {
        while((c = getopt(argc, argv, "f:n:p:")) != -1)
        {
            switch(c)
            {
                case 'f':   //Database file
                    params->f = 1;
                    params->fname = optarg;
                    break;
                case 'n':   //Number of pipes
                    params->n = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                case 'p':   //Main Named Pipe
                    params->p = 1;
                    params->pname = optarg;
                    sprintf(mpn, "/tmp/%s", params->pname);
                    mkfifo(mpn, S_IRUSR | S_IWUSR);
                    break;
                default:
                    fprintf(stderr, "Unknown parameter -%c\n", c);
            }
        }
    }
    
    if(params->f != 1)
        params->fname = DEFAULT_DB_FILE;
    
    if(params->p != 1)
        strcpy(mpn, MEDIT_DEFAULT_MAIN_PIPE);

    options = malloc(sizeof(Settings));

    ParseEnvVars(options);
    
    pthread_create(&mpipe_thread, NULL, MainPipeHandler, (void*) mpn);
    
    do
    {
        pthread_create(&cmd_thread, NULL, ParseCommands, NULL);
        pthread_join(cmd_thread, NULL);
    }
    while(ExitVar != 1);
    
    free(options);
    free(params);
    
    pthread_kill(mpipe_thread, SIGINT);
    pthread_join(mpipe_thread, NULL);
    execlp("rm", "rm", mpn, NULL);
    
    if(params->p == 1)
        execlp("rm", "rm", MEDIT_DEFAULT_MAIN_PIPE, NULL);
    
    return (EXIT_SUCCESS);
}
