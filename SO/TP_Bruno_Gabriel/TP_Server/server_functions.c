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