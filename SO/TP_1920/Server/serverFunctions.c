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
        if (!strcmp(cmd, "help"))
        {
            printf("Even I don't know\n");
        }
        else if (!strcmp(cmd, "msg"))
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

int createServerFiles()
{
    struct stat tmpstat = {0};
    
    if(stat(MSGDIST_DIR, &tmpstat) == -1)
    {
        if(mkdir(MSGDIST_DIR, 0744) == -1)
        {
            printf("Directory Creation: %d\n", errno);
            return -1;
        }
    }
        
    int server_file = open(SERVER_PID, O_RDWR | O_CREAT, 0644);
    
    if(server_file == -1)
    {
        printf("File Creation: %d\n", errno);
        return -1;
    }
    
    return 0;
}