#include "headers.h"
#include "Interface.h"

int main(int argc, char** argv)
{
    Interface::SetScreenSize(MAX_Y, MAX_X);
    
    /* INICIAR NCURSES */
    initscr();
    start_color();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    char opt;
    int r, flag;
    
    /* PEDE E VERIFICA A LINGUAGEM */
    while(opt != '1' && opt != '2')
    {
        clear();
        mvwaddstr(stdscr, Interface::getVertCenter(stdscr, 1, r, flag) - 1, Interface::getCenter("1 - Português"), "1 - Portugues");
        mvwaddstr(stdscr, Interface::getVertCenter(stdscr, 1, r, flag) + 1, Interface::getCenter("2 - English") - 1, "2 - English");
        refresh();
        opt = getch();
    }
    
    Interface game(opt);
    
    clear();
    mvwaddstr(stdscr, ((game.getVertCenter(stdscr, 1, r, flag)) + r) - 1, game.getCenter(game.getLine(1)), game.getLine(1));
    mvwaddstr(stdscr, ((game.getVertCenter(stdscr, 1, r, flag)) + r) + 1, game.getCenter(game.getLine(0)), game.getLine(0));
    refresh();
    getch();
    clear();
    
    do
    {
        game.drawBox(stdscr);
        game.drawMainMenu();
        opt = getch();

        switch(opt)
        {
            case '1':
                game.drawBox(stdscr);
		game.startgame();
                break;
            case '2':
                game.drawBox(stdscr);
                game.tutPage();
                break;
            case '3':
                game.drawBox(stdscr);
                game.credPage();
                break;
            case '4':
                game.drawBox(stdscr);
                mvwaddstr(stdscr, ((game.getVertCenter(stdscr, 1 ,r, flag)) + r) + 1, game.getCenter(game.getLine(46)), game.getLine(46));
                refresh();
                getch();
                break;
            default:
                break;
        }                
    }
    while(opt != '4');
    
    /* TERMINAR NCURSES */
    endwin();
    
    return 0;
}

