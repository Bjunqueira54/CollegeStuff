#include "client.h"

//Should be working 100%
void addNewClient(pClient listStart, pClient newClient)
{
    if(listStart == NULL)
    {
        newClient->next = newClient->prev = NULL;
        listStart = newClient;
        return;
    }
    
    pClient aux = listStart;
    
    if(aux->next == NULL)
    {
        aux->next = newClient;
    }
    else
    {
        while(aux->next != NULL)
            aux = aux->next;
        
        aux->next = newClient;
    }
}

void removeClient(pClient listStart, pClient cli)
{
    if(listStart == NULL)
        return;
    else
    {
        pClient auxNext = cli->next;
        pClient auxPrev = cli->prev;

        auxPrev->next = auxNext;
        auxNext->prev = auxPrev;

        free(cli);
    }
}

pClient findClientByUsername(pClient listStart, char* username)
{
    if(listStart == NULL)
        return NULL;
    
    pClient aux = listStart;
    
    while(aux->next != NULL)
    {
        if(strcmp(aux->username, username) == 0)
            return aux;
    }
    
    return NULL;
}

pClient findClientByPID(pClient listStart, pid_t PID)
{
    if(listStart == NULL)
        return NULL;
    
    pClient aux = listStart;
    
    while(aux->next != NULL)
    {
        if(aux->c_PID == PID)
            return aux;
    }
    
    return NULL;
}

bool serverMainLoop(char *cmd, pClient aux, char *extra)
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

void serverBroadcastExit(pClient listStart)
{
    if(listStart == NULL)
        return;
    
    pClient aux = listStart;
    
    while(aux != NULL)
    {
        kill(aux->c_PID, SIGINT);
    }
}

void clientSignals(int sigNum, siginfo_t *info)
{
    
}
