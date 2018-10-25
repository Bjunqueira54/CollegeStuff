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
    
    char line[15][15+45+1]; //15 linhas, 15 caracters de precedencia + 45 colunas + \0. Valores por defeito até ser implementada comunicação
    char* curline; //Linha atual, 15 caracters de precedencia + 45 colunas + \0.
    curline = malloc((15+45+1)*sizeof(char));
    char preline[15+45+1]; //Linha antes de entrar no modo de edição
    int x, newx, y, newy;
    int c;
    int mode = 0; //Var. para determinar se estamos em modo de edição ou de seleção. 0=Seleção, 1=Edição, 2=Exit
    
    /////////////////////////////////////////////
    ///// Inicialização da string principal /////
    /////////////////////////////////////////////
    
    for(int y=0; y<15; y++)
    {
        for(int x=0; x<15+45+1; x++)
            line[y][x] = ' ';
        line[y][45+15+1] = '\0';
    }
    
    ////////////////////////////////////////////////////////////
    ///// Inicio da janela de ncurses para edição de texto /////
    ////////////////////////////////////////////////////////////
    
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    
    for(y=1; y<=9; y++)
    {
        curline = preLinePrep(curline, 45+1, y);
        mvaddstr(y-1, 0, curline);
        for(x=0; x<15+45+1; x++)
            line[y-1][x] = curline[x];
    }
    for(y=10; y<=15; y++)
    {
        curline = preLinePrep(curline, 45+1, y);
        mvaddstr(y-1, 0, curline);
        for(x=0; x<15+45+1; x++)
            line[y-1][x] = curline[x];
    }
    refresh();

    move(0, 16);
    
    do
    {
        if(mode == 0)
        {
            mode = mvModeLoop();
            
            if(mode == 4)
            {
                getyx(stdscr, y, x);
                for(x=0; x<46; x++)
                {
                    preline[x] = line[y][x];
                }
                mode = 1;
            }
        }
        else if(mode == 1)
        {
            mode = edModeLoop();
            
            if(mode >= 32 && mode <= 126)
            {
                getyx(stdscr, y, x);
                newx = x;
                newy = y;
                line[y][x-4] = mode;
                mode = 1;
                move(newy, newx+1);
            }
            if(mode == 3)
            {
                getyx(stdscr, y, x);
                newx=x;
                x-=4;
                newy=y;
                line[y][45] = ' ';
                for(;x<46; x++)
                {
                    line[y][x-1] = line[y][x];
                }
                line[y][45] = '\0';
                move(newy, newx-1);
                mode = 1;
            }
            else if(mode == 5)
            {
                getyx(stdscr, y, x);
                for(x=0; x<46; x++)
                {
                    line[y][x] = preline[x];
                }
                mode = 0;
            }

            getyx(stdscr, y, x);
            newx=x;
            newy=y;
            for(y=0; y<15; y++)
            {
                for(x=0; x<46; x++)
                {
                    curline[x] = line[y][x];
                }
                mvwaddstr(stdscr, y, 4, curline);
            }
            move(newy, newx);
        }
        refresh();
    }
    while(mode != 2);
    
    endwin();
    return (EXIT_SUCCESS);
}

