#include "server.h"

int mp;

void SigHandler(int signal)
{
    close(mp);
    pthread_exit(NULL);
}

void CheckArgs(Params *p)
{
    if(p->f == 1)
        fprintf(stdout, "Database File: %s\n", p->fname);
    else
        fprintf(stdout, "Database File: %s\n", DEFAULT_DB_FILE);
    
    if(p->p == 1)
        fprintf(stdout, "Main Named Pipe: %s\n", p->pname);
    else
        fprintf(stdout, "Main Named Pipe: %s\n", MEDIT_DEFAULT_MAIN_PIPE);
    
}

void CheckOptions(Settings *a)
{
    fprintf(stdout, "Max Lines: %i\n", a->lines);
    fprintf(stdout, "Max Columns: %i\n", a->columns);
    fprintf(stdout, "Max Users: %i\n", a->maxusers);
    fprintf(stdout, "User Line Timeout: %i\n", a->timeout);
}

void ParseEnvVars(Settings *a)
{
    char* env;

    if((env = getenv("MEDIT_MAXLINES")) != NULL)
    {
        a->lines = atoi(env);
        if(a->lines <= 0 || a->lines > MEDIT_MAXLINES)
            a->lines = MEDIT_MAXLINES;
    }
    else
        a->lines = MEDIT_MAXLINES;
    
    if((env = getenv("MEDIT_MAXCOLUMNS")) != NULL)
    {
        a->columns = atoi(env);
        if(a->columns <= 0 || a->columns > MEDIT_MAXCOLUMNS)
            a->columns = MEDIT_MAXCOLUMNS;
    }
    else
        a->columns = MEDIT_MAXCOLUMNS;
    
    if((env = getenv("MEDIT_TIMEOUT")) != NULL)
    {
        a->timeout = atoi(env);
        if(a->timeout <= 0)
            a->timeout = MEDIT_TIMEOUT;
    }
    else
        a->timeout = MEDIT_TIMEOUT;
    
    if((env = getenv("MEDIT_MAXUSERS")) != NULL)
    {
        a->maxusers = atoi(env);
        if(a->maxusers <= 0 || a->maxusers > MEDIT_MAXLINES)
            a->maxusers = MEDIT_MAXUSERS;
    }
    else
        a->maxusers = MEDIT_MAXUSERS;
}

void ValidateNewClient(const char* newuser)
{
    FILE *db = fopen(params->fname, "rt");
    
    fclose(db);
}

void* ParseCommands()
{
    char cmd[25];
    fprintf(stdout, "Command: ");
    fgets(cmd, 25, stdin);
    cmd[strlen(cmd)-1] = '\0';  //Replaces '\n' with '\0'
    int scount=0;
    
    for(int i=0; i<strlen(cmd); i++)
    {
        cmd[i] = tolower(cmd[i]);
        if(cmd[i] == ' ')
        {
            scount++;
            break;
        }
    }
    
    if(strcmp(cmd, "settings") == 0)
    {
        CheckArgs(params);
        CheckOptions(options);
    }
    else if(strcmp(cmd, "shutdown") == 0)
        ExitVar = 1;
    else if(strcmp(cmd, "statistics") == 0)
        fprintf(stderr, "Coming soon...\n");
    else if(strcmp(cmd, "users") == 0)
        fprintf(stderr, "Coming soon...\n");
    else if(strcmp(cmd, "text") == 0)
        fprintf(stderr, "Coming soon...\n");
    else if(scount > 0)
    {
        char argument[20];
        cmd[4] = '\0';

        for(int i=0, j=5; j<20; i++, j++)
        {
            argument[i] = cmd[j];
            cmd[j] = '\0';
        }
        
        if(strcmp(cmd, "load") == 0)
        {
            fprintf(stdout, "Coming soon...\n");

            FILE *load = fopen(argument, "rt");

            if(load == NULL)
                fprintf(stderr, "File either does not exist in directory or name too long\n");
            else
                fprintf(stdout, "If this command was working, file %s would be loaded\n", argument);
        }
        else if(strcmp(cmd, "save") == 0)
        {
            fprintf(stdout, "Coming soon...\n");
            FILE *save = fopen(argument, "rt");

            if(save == NULL)
                fprintf(stderr, "File either does not exist in directory or name too long\n");
            else
                fprintf(stdout, "If this command was working, file %s would be saved\n", argument);
        }
        else if(strcmp(cmd, "free") == 0)
        {
            fprintf(stdout, "Coming soon...\n");

            int line;
            line = atoi(argument);
            
            if(cmd <= 0)
                fprintf(stderr, "Invaline line number.\n");
            else
                fprintf(stdout, "If this command was working, line %i would be forcefully free now.\n", line);
        }
    }
    else
        fprintf(stderr, "Unknown command!\n");
        
    return NULL;

}

void* MainPipeHandler(void* arg)
{
    int bytesread;
    char username[8];
    char* pipename = (char*) arg;
    struct sigaction action;
    
    action.sa_handler = &SigHandler;
    
    sigaction(SIGINT, &action, NULL);
    
    fprintf(stdout, "Opening pipe %s\n", pipename);
    mp = open(MEDIT_DEFAULT_MAIN_PIPE, O_RDONLY);
    
    bytesread = read(mp, username, 8*sizeof(char));
    
    if(username[bytesread-1] == '\n')
        username[bytesread-1] == '\0';

    
}