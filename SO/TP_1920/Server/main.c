#include <limits.h>
#include <ncurses.h>

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
    char *cmd;

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
        if (cmd == "shutdown")
        {
            Exit = true;
        }
        //Add server code in here
    }

    return (EXIT_SUCCESS);
}