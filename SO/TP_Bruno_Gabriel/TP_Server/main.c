#include "server.h"

Params *params;
Settings *options;
int ExitVar = 0;

int main(int argc, char** argv)
{
    int mp;
    char processid[19];
    char idnum[8];
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
        pthread_create(&mpipe_thread, NULL, MainPipeHandler, NULL);


    ///////////////////////////////////////////////////////////////////
    ///Algoritmo antigo de deteção do servidor. Keep it just because///
    ///////////////////////////////////////////////////////////////////
    
    /*FILE *pExists = popen("pidof tp_server", "r");
    fgets(processid, 19, pExists);
    pclose(pExists);
    
    int i, j=0;
    
    for(i=0; i<strlen(processid); i++)
    {
        if(processid[i] == ' ')
        {
            idnum[j] = '\0';
            j=0;
            pid = strtoul(idnum, NULL, 10);

            if(pid != self)
            {
                fprintf(stderr, "Process already exists\nEXITING!\n");
                return (EXIT_FAILURE);
            }
        }
        else
        {
            idnum[j] = processid[i];
            j++;
        }
    }
    
    pid = strtoul(idnum, NULL, 10);
    
    if(pid != self)
    {
        fprintf(stderr, "Process already exists\nEXITING!\n");
        return (EXIT_FAILURE);
    }*/

    params = malloc(sizeof(Params));
    params->f = 0;
    params->n = 0;
    params->p = 0;

    FILE *db;
    char c;

    if(argc != 1)
    {
        while((c = getopt(argc, argv, "f:n:p:")) != -1)
        {
            switch(c)
            {
                case 'f':
                    params->f = 1;
                    params->fname = optarg;
                    break;
                case 'n':
                    params->n = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                case 'p':
                    params->p = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                default:
                    fprintf(stderr, "Unknown parameter -%c\n", c);
            }
        }
    }

    options = malloc(sizeof(Settings));

    ParseEnvVars(options);
    
    char line[options->lines][15+options->columns+1];
    char curLine[15+options->columns+1];
    char preLine[15+options->columns+1];

    if(params->f == 1)
    {
        db = fopen(params->fname, "a+t");
    }
    else
    {
        db = fopen(DEFAULT_DB_FILE, "a+t");
    }
       
    do
    {
        pthread_create(&cmd_thread, NULL, ParseCommands, NULL);
        pthread_join(cmd_thread, NULL);
    }
    while(ExitVar != 1);
    
    fclose(db);
    free(options);
    free(params);
    
    pthread_kill(mpipe_thread, SIGINT);
    pthread_join(mpipe_thread, NULL);
    execlp("rm", "rm", MEDIT_DEFAULT_MAIN_PIPE, NULL);
    
    return (EXIT_SUCCESS);
}
