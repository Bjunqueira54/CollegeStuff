#include "serverInterface.h"

void serverMainOutput(int flag)
{
    switch(flag)
    {
        case 0: // Command
            fprintf(stdout, "\nComando: ");
            return;
        case 1: // Server Shutdown
            fprintf(stdout, "Gestor vai desligar\n");
            return;
        case 2: // Invalid Command
            fprintf(stdout, "Comando invalido\n\n");
            return;
        case 3: // Help
            fprintf(stdout, "        shutdown - Desliga o gestor\n");
            fprintf(stdout, "           users - Listar utilizadores\n");
            fprintf(stdout, "  kick -u <user> - Excluir utilizador\n");
            fprintf(stdout, "             msg - Listar mensagens\n");
            fprintf(stdout, "    del -m <msg> - Listar mensagens\n");
            fprintf(stdout, "          topics - Listar topicos\n");
            fprintf(stdout, "topic -t <topic> - Listar mensagens do topico\n");
            fprintf(stdout, "           prune - Eliminar topicos vazios\n");
            return;
        default:
            fprintf(stderr, "Erro\n");
            return;
    }
}
