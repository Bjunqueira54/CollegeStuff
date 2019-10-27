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
        if (!strcmp(cmd, "msg"))
        {
            return false;
        }
        else if (!strcmp(cmd, "users"))
        {
            return false;
        }
        else if (!strcmp(cmd, "topics"))
        {
            return false;
        }
        else if (!strcmp(cmd, "filter") && !strcmp(opt, "on"))
        {
            if (Filter == false)
            {
                Filter = true;
                return false;
            }
            
            return false;
        }
        else if (!strcmp(cmd, "filter") && !strcmp(opt, "off"))
        {
            if (Filter == true)
            {
                Filter = false;
                return false;
            }
            
            return false;
        }
    }
    
    serverMainOutput(-1, "\0");
    return false;
}