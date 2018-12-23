#include <stdio.h>
#include <stdlib.h>

#include "../medit_defaults.h"
#include "client.h"  

/* VARIAVEIS GLOBAIS */

char** line;

int main(int argc, char** argv)
{
    /* PROCESSAMENTO DE ARGUMENTOS */
    
    char username[MEDIT_MAXNAME];
    char pipename[15];
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
                    memcpy(username, optarg, MEDIT_MAXNAME*sizeof(char));
                    break;
                case 'p':
                    p=1;
                    sprintf(pipename, "/tmp/%s", optarg);
                    break;
                default:
                    fprintf(stderr, "Unknown parameters -%c\n", c);
            }
        }
    }
    
    /* VARIAVEIS NECESSARIAS PARA EDICAO DE TEXTO */
    
    char* curline = malloc((STRING_FORM+1) * sizeof(char)); // Linha atual - 15 char iniciais + 45 colunas + \0
    char preline[STRING_FORM+1];
    int x, newx, y, newy;
    
    /* INICIALIZACAO DA STRING PRINCIPAL */
    
    for(int y=0; y<MEDIT_MAXLINES; y++)
    {
        for(int x=0; x<STRING_FORM; x++)
            line[y][x] = ' ';

        line[y][STRING_FORM] = '\0';
    }
    
    /* INICIO DAS NCURSES */
    
    initscr();
    noecho();
    keypad(stdscr,TRUE);
    
    /* TERMINA NCURSES */
    
    endwin();
    
    return(EXIT_SUCCESS);
}