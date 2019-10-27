#include "serverHeader.h"

//Server
int main(int argc, char** argv)
{
    pClient clientList = NULL;
    bool Exit = false;
    bool Filter = true;
    
    //Vars for EnvVars
    int maxMessage;
    int maxNot;
    char* wordNot;
    char cmd[CMD_SIZE];
    
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
    
    char opt[4];
    
    //Server Main Loop
    while(!Exit)
    {
        fprintf(stdout, "Comando: ");
        fscanf(stdin, "%s", cmd);
        
        if (strcmp(cmd, "filter") == 0)
        {
            fprintf(stdout, "Option: ");
            fscanf(stdin, "%s", opt);
        }
        
        Exit = serverMainLoop(cmd, opt, clientList, &Filter);
    }
    
    fprintf(stdout, "Server Shutting Down\n");
    //getchar();

    return (EXIT_SUCCESS);
}