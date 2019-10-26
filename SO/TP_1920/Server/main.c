#include "serverHeader.h"

//Server
int main(int argc, char** argv)
{
    pClient clientList = NULL;
    bool Exit = false;
    
    //Vars for EnvVars
    int maxMessage;
    int maxNot;
    char* wordNot;
    char cmd[20];
    
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
        fprintf(stdout, "Comando: ");
        fscanf(stdin, "%s", cmd);
        
        Exit = serverMainLoop(cmd, clientList);
    }
    
    fprintf(stdout, "Server Shutting Down\n");
    //getchar();

    return (EXIT_SUCCESS);
}