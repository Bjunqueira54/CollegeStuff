#include "serverHeader.h"

bool serverMainLoop(char *cmd, char *opt, pClient aux, bool *f)
{
    if (strcmp(cmd, "shutdown") == 0)
    {
        union sigval value;
        value.sival_int = 0;
        
        while(aux != NULL)
        {
            sigqueue(aux->c_PID, SIGINT, value);
            aux = aux->next;
        }
        
        return true;
    }
    else 
    {
        if (strcmp(cmd, "msg") == 0)
        {
            printf("Msg\n"); //PLACEHOLDER
        }
        else if (strcmp(cmd, "users") == 0)
        {
            printf("Users\n"); //PLACEHOLDER
        }
        else if (strcmp(cmd, "topics") == 0)
        {
            printf("Topics\n"); //PLACEHOLDER
        }
        else if ((strcmp(cmd, "filter") == 0) && (strcmp(opt, "on") == 0))
        {
            if ((*f) == false)
            {
                (*f) = true;
                return false;
            }
            
            return false;
        }
        else if ((strcmp(cmd, "filter") == 0) && (strcmp(opt, "off") == 0))
        {
            if ((*f) == true)
            {
                (*f) = false;
                return false;
            }
            
            return false;
        }
    }
    
    printf("Command not recognized\n"); //PLACEHOLDER
    return false;
}