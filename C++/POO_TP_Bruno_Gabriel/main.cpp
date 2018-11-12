#include "Functions.h"
#include "headers.h"
#include "Player.h"
#include "Language.h"

using namespace std;

int main(int argc, char** argv)
{
    setScreenSize(MAP_MAXY, MAP_MAXX);
    initscr();
    start_color();
    noecho();
    curs_set(FALSE);
    
    char opt;
    int r, extra;
    
    /* ==== PEDE E VERIFICA A LINGUAGEM ==== */
    while(opt != '1' && opt != '2')
    {
        mvwaddstr(stdscr, 1, 1, "1 - Português\n 2 - English");
        refresh();
        opt = getch();
    }
    
    clear();
    refresh();
    Language lang((opt == '1') ? 1 : 2); // opt == 1? else opt == 2
        
    mvwaddstr(stdscr, ((getVertCenter(stdscr, 1, r, extra)) + r) - 1, getCenter(lang.getLine(1)), lang.getLine(1));
    mvwaddstr(stdscr, ((getVertCenter(stdscr, 1, r, extra)) + r) + 1, getCenter(lang.getLine(0)), lang.getLine(0));
    
    refresh();
    getch();
    
    do
    {
        drawBox(stdscr);
        drawMainMenu(lang);
        opt = getch();
        
        switch(opt)
        {
            case '1':
                drawBox(stdscr);
                MainGameLoop(lang);
                break;
            case '2':
                drawBox(stdscr);
                lang.tutPage();
                break;
            case '3':
                drawBox(stdscr);
                lang.credPage();
                break;
            case '4':
                drawBox(stdscr);
                mvwaddstr(stdscr, getVertCenter(stdscr, 1, r, extra), getCenter(lang.getLine(17)), lang.getLine(17));
                refresh();
                getch();
                endwin();
                return 0;
            default:
                break;
        }
    }
    while(opt != '4');
    
    endwin();
    return 0;
}