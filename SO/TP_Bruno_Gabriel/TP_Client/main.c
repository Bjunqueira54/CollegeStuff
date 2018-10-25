#include "client.h"

int main(int argc, char** argv)
{
    ////////////////////////////////////////
    ///// Processamento dos argumentos /////
    ////////////////////////////////////////
    
    char username[MAXNAME];
    
    if(argc != 1)
    {
        char c;
        while((c = getopt(argc, argv, "u:p:")) != -1)
        {
            switch(c)
            {
                case 'u':
                    memcpy(username, optarg, 8*sizeof(char));
                    username[MAXNAME-1] = '\0';
                    break;
                case 'p':
                    break;
                default:
                    fprintf(stderr, "Unknown parameters -%c\n", c);
            }
        }
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///// Preparação das variáveis necessárias para a edição de texto /////
    ///////////////////////////////////////////////////////////////////////
    
    char line[15][46]; //15 linhas, 45 colunas + \0. Valores por defeito até ser implementada comunicação
    char linen[5]; //O numero que precede a linha, exemplo: "(03) ...", com 1 espaço extra para '\0'
    char lineu[10][MAXNAME]; //15 linhas, 8 colunas. Serve para mostrar o username na linha se estiver a ser editada
    int x, y;
    int c;
    int mode = 0; //Var. para determinar se estamos em modo de edição ou de seleção. 0=Seleção, 1=Edição, 2=Exit
    
    ////////////////////////////////////////////////////////////
    ///// Inicio da janela de ncurses para edição de texto /////
    ////////////////////////////////////////////////////////////
    
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    
    for(y=0; y<15; y++);
    {
        for(x=5; x<49; x++)
        {
            mvaddch(y, x, ' ');
        }
    }
    refresh();
    
    for(y=1; y<=9; y++)
    {
        sprintf(linen, "(0%i)", y);
        mvaddstr(y-1, 0, linen);
    }
    for(y=10; y<=15; y++)
    {
        sprintf(linen, "(%i)", y);
        mvaddstr(y-1, 0, linen);
    }
    refresh();
    x=4;
    y=0;
    move(y, x);
    
    do
    {
        if(mode == 0)
        {
            mode = mvModeLoop();
        }
        else if(mode == 1)
        {
            mode = edModeLoop();
        }
        else if(mode >= 32 && mode <= 126)
        {
            getyx(stdscr, y, x);
            line[y][x] = mode;
            mvwaddstr(stdscr, y, 4, line[y]);
            mode = 1;
        }
    }
    while(mode != 2);
    
    endwin();
    return (EXIT_SUCCESS);
}

