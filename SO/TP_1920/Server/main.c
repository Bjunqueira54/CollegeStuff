#include "serverHeader.h"

bool Exit;
bool Filter;

//Server
int main(int argc, char** argv)
{
    pClient clientList = NULL;
    
    Exit = false;
    Filter = true;
    
    //Vars for EnvVars
    int maxMessage;
    int maxNot;
    char* wordNot;
    char cmd[CMD_SIZE], opt[4];

    //Signal
    struct sigaction cDisconnect, cSignal;
    
    cSignal.sa_flags = SA_SIGINFO;
    cSignal.sa_sigaction = &clientSignals;
    
    //sigaction(SIGINT, &cDisconnect, NULL);
    sigaction(SIGUSR1, &cSignal, NULL);
    
    //EnvVars
    if(getenv("MAXMSG") != NULL)
        sscanf(getenv("MAXMSG"), "%d", &maxMessage);
    if(getenv("MAXNOT") != NULL)
        sscanf(getenv("MAXNOT"), "%d", &maxNot);
    if(getenv("WORDNOT") != NULL)
        wordNot = getenv("WORDNOT");
    
    
    //Server Main Loop
    while(!Exit)
    {  
        serverMainOutput(1, cmd);
        
        printf("%s\n", cmd);
        
        if (!strcmp(cmd, "filter"))
            serverMainOutput(2, opt);
        
        Exit = serverMainLoop(cmd, opt, clientList);
    }
    
    serverMainOutput(0, "\0");
    
    return (EXIT_SUCCESS);
}