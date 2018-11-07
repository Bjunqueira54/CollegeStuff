#include "server.h"

void CheckArgs(Params *p)
{
    if(p->f == 1)
    {
        fprintf(stdout, "Database File: %s\n", p->fname);
    }
    else
    {
        fprintf(stdout, "Database File: %s\n", DEFAULT_DB_FILE);
    }
    
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

Client* ValidateNewClient(FILE *f, Client *c_vec, int *vec_tam, char *newcli)
{
    char username[MAXNAME];
    
    while(fscanf(f, "%s", username) != EOF)
    {
        if(strcmp(newcli, username) == 0)
        {
            if((*vec_tam) == 0)
            {
                c_vec = malloc(sizeof(Client));
                if(c_vec == NULL)
                {
                    fprintf(stderr, "Memory allocating error for a new client array\n");
                    return NULL;
                }
                (*vec_tam) = 1;
                strcpy(c_vec[0].username, newcli);
                return c_vec;
            }
            else
            {
                c_vec = realloc(c_vec, ((*vec_tam) + 1) * sizeof(Client));
                if(c_vec == NULL)
                {
                    fprintf(stderr, "Memory Re-Allocating error for a new resized client array\n");
                    return c_vec;
                }
                strcpy(c_vec[(*vec_tam)].username, newcli);
                return c_vec;
            }
        }
    }
    
    fprintf(stderr, "Client does not exist on database\n");
    return c_vec;
}

int ParseCommands(Params *params, Settings *options, FILE *f)
{
    char cmd[25];
    fprintf(stdout, "Command: ");
    fflush(stdin);
    fscanf(stdin, "%25[^\n]s", cmd);
    getchar();
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
        return 1;
    }
    else if(strcmp(cmd, "shutdown") == 0)
    {
        fclose(f);

        return 2;
    }
    else if(strcmp(cmd, "statistics") == 0)
    {
        fprintf(stderr, "Coming soon...\n");
        return 1;
    }
    else if(strcmp(cmd, "users") == 0)
    {
        fprintf(stderr, "Coming soon...\n");
        return 1;
    }
    else if(strcmp(cmd, "text") == 0)
    {
        fprintf(stderr, "Coming soon...\n");
        return 1;
    }
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
            {
                fprintf(stderr, "File either does not exist in directory or name too long\n");
                return 1;
            }
            else
            {
                fprintf(stdout, "If this command was working, file %s would be loaded\n", argument);
                return 1;
            }
        }
        else if(strcmp(cmd, "save") == 0)
        {
            fprintf(stdout, "Coming soon...\n");
            FILE *save = fopen(argument, "rt");

            if(save == NULL)
            {
                fprintf(stderr, "File either does not exist in directory or name too long\n");
                return 1;
            }
            else
            {
                fprintf(stdout, "If this command was working, file %s would be saved\n", argument);
                return 1;
            }
        }
        else if(strcmp(cmd, "free") == 0)
        {
            fprintf(stdout, "Coming soon...\n");

            int line;
            line = atoi(argument);
            if(cmd <= 0)
            {
                fprintf(stderr, "Invaline line number.\n");
                return 1;
            }
            else
            {
                fprintf(stdout, "If this command was working, line %i would be forcefully free now.\n", line);
                return 1;
            }
        }
    }
    else
    {
        fprintf(stderr, "Unknown command!\n");
        return 1;
    }
}