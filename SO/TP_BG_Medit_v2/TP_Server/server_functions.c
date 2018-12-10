#include "Server.h"

pClient cl_vec = NULL;

void ClientDisconnect(int signal, siginfo_t *info, void *extra)
{
    fprintf(stdout, "Hello\n");
}

void ClientSignals(int signal, siginfo_t *info, void* extra)
{
    fprintf(stdout, "Hello\n");
}

void ParseEnvVars(Options *a)
{
    char *env;
    
    if((env = getenv("MEDIT_MAXLINES")) != NULL)
    {
        a->lines = atoi(env);
        if(a->lines <=0 || a->lines >= MEDIT_MAXLINES)
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

void ShowUsers()
{
    if(cl_vec == NULL)
        fprintf(stdout, "No users connected to the server\n");
    else
    {
        pClient aux;
        aux = cl_vec;
        
        while(aux != NULL)
        {
            fprintf(stdout, "Username: %s\n", aux->name);
            fprintf(stdout, "ID: %i\n", aux->id);
            if(aux->current == -1)
                fprintf(stdout, "Not currently editing a line\n");
            else
                fprintf(stdout, "Currently editing line %i\n", aux->current);
            fprintf(stdout, "Client reading pipe: %s\n", aux->piperead);
            fprintf(stdout, "Client writing pipe: %s\n", aux->pipewrite);
            
            aux = aux->next;
        }
    }
}

void CheckParams()
{
    if(params->f == 1)
        fprintf(stdout, "Database File: %s\n", params->fname);
    else
        fprintf(stdout, "Database File: %s\n", DEFAULT_DB_FILE);
    
    if(params->p == 1)
        fprintf(stdout, "Main Named Pipe: %s\n", params->pname);
    else
        fprintf(stdout, "Main Named Pipe: %s\n", MEDIT_DEFAULT_MAIN_PIPE);
}

void CheckOptions()
{
    fprintf(stdout, "Max Lines: %i\n", options->lines);
    fprintf(stdout, "Max Columns: %i\n", options->columns);
    fprintf(stdout, "Max Users: %i\n", options->maxusers);
    fprintf(stdout, "User Line Timeout: %i\n", options->timeout);
}

void* ParseCommands()
{
    char cmd[25];
    fprintf(stdout, "Command: ");
    fgets(cmd, 25, stdin);
    cmd[strlen(cmd)-1] = '\0';  //Replaces '\n' with '\0'
    int spaces = 0;
    
    for(int i=0; i<strlen(cmd); i++)
    {
        cmd[i] = tolower(cmd[i]);
        if(cmd[i] == ' ')
        {
            spaces++;
            break;
        }
    }
    
    if(strcmp(cmd, "settings") == 0)
    {
        CheckParams();
        CheckOptions();
    }
    else if(strcmp(cmd, "shutdown") == 0)
        ExitVar = 1;
    else if(strcmp(cmd, "statistics") == 0)
        fprintf(stderr, "Soon(tm)...\n");
    else if(strcmp(cmd, "users") == 0)
        ShowUsers();
    else if(strcmp(cmd, "text") == 0)
        fprintf(stderr, "Soon(tm)...\n");
    else if(spaces > 0)
    {
        
    }
    else
        fprintf(stderr, "Unknown command!\n");
    
    return NULL;
}