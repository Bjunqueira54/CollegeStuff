#include "serverHeader.h"

bool serverMainLoop(char *cmd, char *opt, pClient aux)
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
        //int flag = parseCmd(cmd);
        
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
            printf("filter on\n"); //PLACEHOLDER
        }
        else if ((strcmp(cmd, "filter") == 0) && (strcmp(opt, "off") == 0))
        {
            printf("filter off\n"); //PLACEHOLDER
        }
        else 
        {
            printf("Command not recognized\n"); //PLACEHOLDER
        }
    }
    
    return false;
}