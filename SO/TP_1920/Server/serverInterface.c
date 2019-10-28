#include "serverInterface.h"

void serverMainOutput(int flag)
{
    switch(flag)
    {
        case 0: // Command
            fprintf(stdout, "Comando: ");
            return;
        case 1: // Server Shutdown
            fprintf(stdout, "Gestor vai desligar\n");
            return;
        case 2: // Invalid Command
            fprintf(stdout, "Comando invalido\n");
            return;
        case 3: // Help
            fprintf(stdout, "     shutdown - Desliga o gestor\n");
            fprintf(stdout, "        users - Listar utilizadores\n");
            fprintf(stdout, "  kick <user> - Excluir utilizador\n");
            fprintf(stdout, "          msg - Listar mensagens\n");
            fprintf(stdout, "    del <msg> - Listar mensagens\n");
            fprintf(stdout, "       topics - Listar topicos\n");
            fprintf(stdout, "topic <topic> - Listar mensagens do topico\n");
            fprintf(stdout, "        prune - Eliminar topicos vazios\n\n");
            return;
        default:
            fprintf(stderr, "Erro\n");
            return;
    }
}