#include "client.h"

void addNewClient(pClient listStart, pClient newClient)
{
    pClient aux = listStart;
    
    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    
    aux->next = newClient;
    newClient->prev = aux;
    newClient->next = NULL;
}

void removeClient(pClient listStart, pClient cli)
{
    pClient auxNext = cli->next;
    pClient auxPrev = cli->prev;
    
    auxPrev->next = auxNext;
    auxNext->prev = auxPrev;
    
    free(cli);
}

pClient findClientByUsername(pClient listStart, char* username)
{
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
    pClient aux = listStart;
    
    while(aux->next != NULL)
    {
        if(aux->c_PID == PID)
            return aux;
    }
    
    return NULL;
}

void serverBroadcastExit()
{
    
}

void clientSignals()
{
    
}