#include "Functions.h"
#include "headers.h"
#include "Player.h"
#include "Language.h"

#define MAP_MAXY 40     //Merchants and Pirates Max Height
#define MAP_MAXX 120    //Merchants and Pirates Max Width

using namespace std;

int main(int argc, char** argv)
{
    setScreenSize(MAP_MAXY, MAP_MAXX);
    initscr();
    noecho();
    
    char opt;
    
    /* ==== PEDE E VERIFICA A LINGUAGEM ==== */
    while(opt != '1' && opt != '2')
    {
        mvwaddstr(stdscr, 1, 1, "Portugues - 1\n English - 2\n\n ->");
        refresh();
        opt = getch();
    }
    
    clear();
    refresh();
    Language lang((opt == '1') ? 1 : 2); // opt == 1? else opt == 2
        
    mvwaddstr(stdscr, 9, getCenter(lang.getLine(1)), lang.getLine(1));
    mvwaddstr(stdscr, 11, getCenter(lang.getLine(0)), lang.getLine(0));
    
    refresh();
    getch();
    
    do
    {
        drawMainMenu(lang);
        opt = getch();
        
        switch(opt)
        {
            case '1':
                MainGameLoop(lang);
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                clear();
                mvwaddstr(stdscr, getmaxy(stdscr) / 2, getCenter(lang.getLine(17)), lang.getLine(17));
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