#include <limits.h>

#include "serverHeader.h"

//Server
int main(int argc, char** argv)
{
    char maxMsg[5] = getenv("MAXMSG");
    int maxMessage;
    
    sscanf(maxMsg, &maxMessage);
    
    return (EXIT_SUCCESS);
}