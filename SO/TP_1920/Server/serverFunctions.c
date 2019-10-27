#include "serverHeader.h"

bool serverMainLoop(char *cmd, pClient aux)
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
            printf("Msg\n");
        }
        else if (strcmp(cmd, "users") == 0)
        {
            printf("Users\n");
        }
        else if (strcmp(cmd, "topics") == 0)
        {
            printf("Topics\n");
        }
        else if (strcmp(cmd, "filter") == 0) //incompleto
        {
            
        }
    }
    
    return false;
}