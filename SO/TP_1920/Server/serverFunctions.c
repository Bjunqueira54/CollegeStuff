#include "serverHeader.h"

void serverMainLoop(char *cmd, pClient aux)
{
    if(stringCompare(cmd, "shutdown"))
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
        if (parseCommands(cmd))
            return;
    
    serverMainOutput(2);
}

bool parseCommands(char *cmd)
{
    if(stringCompare(cmd, "help"))
        serverMainOutput(3);
    else if (stringCompare(cmd, "msg"))
        listAllMesages();
    else if (stringCompare(cmd, "users"))
        listAllUsers();
    else if (stringCompare(cmd, "topics"))
        listAllTopics();
    else if (stringCompare(cmd, "prune"))
        deleteEmptyTopics();
    else if (stringCompare(cmd, "filter on"))
        if (Filter == false)
            Filter = true;
    else if (stringCompare(cmd, "filter off"))
        if (Filter == true)
            Filter = false;
    else
        if(parseOptionCommands(cmd))
            return true;
        else
            return false;
    
    return true;
}

bool parseOptionCommands(char cmd[])
{
    int i = 0;
    char *options[2], *opt = strtok(cmd, " ");
    
    while(opt != NULL) {
        options[i++] = opt;
        opt = strtok(NULL, " ");
    }
    
    switch(getopt(i, options, "m:t:u:")) {
        case 'm':
            if(stringCompare(options[0],"del")) {
                opt = optarg; //nome
                return true;
            }
            return false;
        case 't':
            if(stringCompare(options[0],"topic")) {
                opt = optarg; //nome
                return true;
            }
            return false;
        case 'u':
            if(stringCompare(options[0],"kick")) {
                opt = optarg; //nome
                return true;
            }
            return false;
        default:
            return false;
    }

    return false;
}

bool stringCompare(char *str1, char *str2) //TEM UM BUG
{
    for (int i = 0; i < strlen(str1) - 1; i++)
        if(str1[i] != str2[i])
            return false;
    return true;
}

void listAllUsers() 
{

}

void listAllMesages()
{
    
}

void listAllTopics()
{
    
}

void deleteEmptyTopics() 
{
    
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
