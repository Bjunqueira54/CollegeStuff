#include "client.h"  

/* VARIAVEIS GLOBAIS */

char** line;

int main(int argc, char** argv)
{
    char username[MEDIT_MAXNAME];
    char mainpipe[MEDIT_PIPE_SIZE];
    
    /* PROCESSAMENTO DE ARGUMENTOS */
    
    int u=0, p=0;
    
    if(argc != 1)
    {
        char c;
        while((c = getopt(argc, argv, "u:p:")) != -1)
        {
            switch(c)
            {
                case 'u':
                    u=1;
                    memcpy(username, optarg, MEDIT_MAXNAME * sizeof(char));
                    break;
                case 'p':
                    p=1;
                    sprintf(mainpipe, "/tmp/%s", optarg);
                    break;
                default:
                    fprintf(stderr, "Unknown parameters -%c\n", c);
            }
        }
    }   
    
    /* VARIAVEIS NECESSARIAS PARA EDICAO DE TEXTO */
    
    char* curline = malloc((STRING_FORM + 1) * sizeof(char));
    char preline[STRING_FORM + 1];
    pthread_t update, stats;
    int x, newx, y, newy;
    
    /* ALOCAR MEMORIA PARA ESCRITA */
    
    line = malloc(MEDIT_MAXLINES * sizeof(char));
    if(line == NULL)
        exit(EXIT_FAILURE);
    
    for(int i=0; i<MEDIT_MAXLINES; i++)
    {
        line[i] = malloc(STRING_FORM * sizeof(char));
        if(line[i] == NULL)
        {
            for( ; i>=0; i--)
            {
                free(line[i]);
            }
            free(line);
            exit(EXIT_FAILURE);
        }
    }
    
    /* INICIALIZACAO DA STRING PRINCIPAL */
    
    for(int y=0; y<MEDIT_MAXLINES; y++)
    {
        for(int x=0; x<STRING_FORM; x++)
            line[y][x] = ' ';

        line[y][STRING_FORM] = '\0';
    }
    
    /* INICIO DAS NCURSES */
    {
        initscr();
        noecho();
        keypad(stdscr,TRUE);
    }
    
    /* ENVIAR PARA O MAINPIPE */
    
    int cfd;
    
    /* PREPARACAO DE SINAIS */
    
    struct sigaction invalid_username, sv_con, sv_disc;

    invalid_username.sa_flags = SA_SIGINFO;
    invalid_username.sa_sigaction = &invUser;
    
    sv_con.sa_flags = SA_SIGINFO;
    sv_con.sa_sigaction = &serverConnect;
    
    sv_disc.sa_handler = &serverDisconnect;
    
    sigaction(SIGINT, &invalid_username, NULL);
    sigaction(SIGUSR1, &sv_con, NULL);
    sigaction(SIGUSR2, &sv_disc, NULL);
    
    /* TERMINA NCURSES */
    
    endwin();
    
    return(EXIT_SUCCESS);
}