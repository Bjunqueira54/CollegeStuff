#include <limits.h>
#include <ncurses.h>

#include "serverHeader.h"

//Server
int main(int argc, char** argv)
{
    //char maxMsg[5] = getenv("MAXMSG");
    int maxMessage;

    //sscanf(maxMsg, &maxMessage);
    
    pText testeMsg;
    testeMsg = malloc(sizeof(Text));
    
    testeMsg->duration = 15;
    
    getchar();

    return (EXIT_SUCCESS);
}