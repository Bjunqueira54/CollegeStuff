#include "serverHeader.h"

void serverMainLoop(char *cmd, pClient aux)
{
    if (stringCompare(cmd, "shutdown"))
    {
        union sigval value;
        value.sival_int = 0;
        
        while(aux != NULL)
        {
            sigqueue(aux->c_PID, SIGINT, value);
            aux = aux->next;
        }
        
        Exit = true;
        return;
    }
    else 
    {
        if (stringCompare(cmd, "help"))
        {
            serverMainOutput(3);
            return;
        }
        else if (stringCompare(cmd, "msg"))
        {
            return;
        }
        else if (stringCompare(cmd, "users"))
        {
            return;
        }
        else if (stringCompare(cmd, "topics"))
        {
            return;
        }
        else if (stringCompare(cmd, "filter on"))
        {
            if (Filter == false)
                Filter = true;
            return;
        }
        else if (stringCompare(cmd, "filter off"))
        {
            if (Filter == true)
                Filter = false;
            return;
        }        
    }
    
    serverMainOutput(2);
}

bool stringCompare(char *str1, char *str2) 
{
    int n = 0;
    
    for (int i = 0; i < strlen(str2); i++)
        if (str1[i] == str2[i])
            n++;
    
    if (n == strlen(str2))
        return true;
    
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