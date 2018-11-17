#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

WINDOW *wmap, *wcmd, *wlog;
int phase = 1;

void MainGameLoop(Language lang)
{
    int turn=0;
    int r, extra;
    char opt;
    string name, cmd, aux;
    
    do
    {
        drawBox(stdscr);
        mvwaddstr(stdscr, 2, 2, lang.getLine(6));
        mvwaddstr(stdscr, 4, 2, lang.getLine(7));
        mvwaddch(stdscr, 4, 2 + strlen(lang.getLine(7)), '_');
        refresh();

        opt = 0;

        name = getInput(stdscr, 20);

        if(name.empty())
            mvwaddstr(stdscr, 1, 2, lang.getLine(8));
    }
    while(name.empty());

    Player player(name);

    clear();

    aux.clear();
    aux = lang.getLine(10);
    aux += name;
    
    drawBox(stdscr);
    mvwaddstr(stdscr, getVertCenter(stdscr, 1, r, extra) - 1, getCenter(aux), aux.c_str());
    mvwaddstr(stdscr, getVertCenter(stdscr, 1, r, extra) + 1, getCenter(lang.getLine(0)), lang.getLine(0));

    refresh();
    getch();
    
    wmap = subwin(stdscr, 20, 40, 0, 0);
    wcmd = subwin(stdscr, 20, 40, getmaxy(wmap), 0);
    wlog = subwin(stdscr, MAP_MAXY, MAP_MAXX-getmaxx(wmap), 0, getmaxx(wmap));
    clear();

    do  //Main Game Loop
    {
        ostringstream sturn;

        {
            drawBox(wmap);
            drawMap();
            drawBox(wcmd);
            drawBox(wlog);
        }
        
        if(phase == 1)
        {
            mvwaddstr(wcmd, 1, 1, lang.getLine(27));
            mvwaddstr(wcmd, 1, strlen(lang.getLine(27))+1, "1");
            wrefresh(wcmd);
        }
        else
        {
            turn++;
            mvwaddstr(wcmd, 1, 1, lang.getLine(11));
            sturn << turn;
            mvwaddstr(wcmd, 1, strlen(lang.getLine(11)) + 1, sturn.str().c_str());
            wrefresh(wcmd);
        }
        
        do  //Phase 1: Command parsing and Processing
        {
            cmd.clear();
            mvwaddstr(wcmd, getmaxy(wcmd)-3, 1, lang.getLine(12));
            wclrtoeol(wcmd);
            mvwaddch(wcmd, getmaxy(wcmd)-3, getmaxx(wcmd)-1, '|');
            mvwaddch(wcmd, getmaxy(wcmd)-3, 1 + strlen(lang.getLine(12)), '_');
            wrefresh(wcmd);
            
            cmd = getInput(wcmd, 20);
            
            if(cmd.empty())
            {
                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(13));
            }
            else if(cmd == lang.getCmd(2) || cmd == lang.getCmd(20))
            {
                break;
            }
            else
            {
                if(parseCmd(cmd, phase, lang) == false)
                {
                    mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(25));
                    wclrtoeol(wcmd);
                    mvwaddch(wcmd, getmaxy(wcmd)-2, getmaxx(wcmd)-1, '|');
                }
            }
        }
        while(cmd != lang.getCmd(2) && cmd != lang.getCmd(20));
        
        if(cmd == lang.getCmd(20))
            break;
        
        //IMPLEMENT PHASE 2 HERE
        /*
         
         */
    }
    while(cmd != lang.getCmd(20));
    
    delwin(wmap);
    delwin(wcmd);
    delwin(wlog);
}