#include "serverHeader.h"

//Server
int main(int argc, char** argv)
{
    pClient ClientList = NULL;
    bool Exit = false;
    
    //Vars for EnvVars
    int maxMessage;
    int maxNot;
    char* wordNot;
    char cmd[20];
    
    struct sigaction cDisconnect, cSignal;

    cDisconnect.sa_flags = SA_SIGINFO;
    cDisconnect.sa_sigaction = &serverBroadcastExit;
    
    cSignal.sa_flags = SA_SIGINFO;
    cSignal.sa_sigaction = &clientSignals;
    
    sigaction(SIGUSR1, &cDisconnect, NULL);
    sigaction(SIGUSR2, &cSignal, NULL);
    
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
        fprintf(stdout, "Comando: ");
        fscanf(stdin, "%s", cmd);
        
        if (strcmp(cmd, "shutdown") == 0)
        {
            Exit = true;
        }
        //Add server code in here
    }

    return (EXIT_SUCCESS);
}