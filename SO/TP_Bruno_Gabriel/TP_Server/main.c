#include "server.h"

int ExitVar = 0;

int main(int argc, char** argv)
{
    char processid[19];
    char idnum[8];

    FILE *pExists = popen("pidof tp_server", "r");
    fgets(processid, 19, pExists);
    pclose(pExists);
    
    pid_t pid, self;
    self = getpid();
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
    }

    Params params;
    params.f = 0;
    params.n = 0;
    params.p = 0;

    FILE *f;
    char c;
    pthread_t cmd_thread, mpipe_thread;

    if(argc != 1)
    {
        while((c = getopt(argc, argv, "f:n:p:")) != -1)
        {
            switch(c)
            {
                case 'f':
                    params.f = 1;
                    params.fname = optarg;
                    break;
                case 'n':
                    params.n = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                case 'p':
                    params.p = 1;
                    fprintf(stdout, "I still do not know how to use -%c\n", c);
                    break;
                default:
                    fprintf(stderr, "Unknown parameter -%c\n", c);
            }
        }
    }

    Settings *options = malloc(sizeof(Settings));

    ParseEnvVars(options);
    
    char line[options->lines][15+options->columns+1];
    char curLine[15+options->columns+1];
    char preLine[15+options->columns+1];

    if(params.f == 1)
    {
        f = fopen(params.fname, "a+t");
    }
    else
    {
        f = fopen(DEFAULT_DB_FILE, "a+t");
    }
    
    ParseCommands(&params, options, f) == 1
    
    while(ExitVar != 1);
    free(options);
}
