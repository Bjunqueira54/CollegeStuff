#include "client.h"

void addNewClient(pClient listStart, pClient newClient)
{
    if(listStart->next == NULL) 
    {
        listStart->next = newClient; 
    }
    else 
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
}

void removeClient(pClient listStart, pClient cli)
{
    if(listStart->next != NULL)
    {    
        pClient auxNext = cli->next;
        pClient auxPrev = cli->prev;

        auxPrev->next = auxNext;
        auxNext->prev = auxPrev;

        free(cli);
    }
    else
    {
        fprintf(stderr, "Nao ha clientes para remover\n");
    }
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
}

void serverBroadcastExit(int sigNum, siginfo_t *info)
{
    
}

void clientSignals(int sigNum, siginfo_t *info)
{
    
}
