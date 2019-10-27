#include "serverInterface.h"

void serverMainOutput(int flag, char *aux)
{
    switch(flag)
    {
        case 0:
            fprintf(stdout, "Server Shutting Down\n");
            break;
        case 1:
            fprintf(stdout, "Comando: ");
            fscanf(stdin, "%s", aux);
            break;
        case 2:
            fprintf(stdout, "Option: ");
            fscanf(stdin, "%s", aux);
        default:
            fprintf(stderr, "Erro\n");
            break;
    }
}