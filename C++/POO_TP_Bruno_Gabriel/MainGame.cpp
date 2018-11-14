#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

void MainGameLoop(Language lang)
{
    int turn=0;
    int r, extra, phase = 1;
    char opt;
    string name, cmd, aux;
    
    do
    {
        drawBox(stdscr);
        mvwaddstr(stdscr, 1, 1, lang.getLine(6));
        mvwaddstr(stdscr, 3, 1, lang.getLine(7));
        mvwaddch(stdscr, 3, 1 + strlen(lang.getLine(7)), '_');
        refresh();

        opt = 0;

        do
        {
            opt = getch();

            if((opt == ' ') || (opt >= '0' && opt <= '9') || (opt >= 'A' && opt <= 'Z') || (opt >= 'a' && opt <= 'z'))
            {   //No Special Characters allowed
                if(name.size() < 20)
                {
                    name.push_back(opt);
                    mvwaddstr(stdscr, 3, 1 + strlen(lang.getLine(7)), name.c_str());
                    mvwaddch(stdscr, 3, 1 + strlen(lang.getLine(7)) + strlen(name.c_str()), '_');
                    refresh();
                }
            }
            else if(opt == 8 || opt == 127) // 8 = Backspace, 127 = Delete
            {
                if(!( name.empty() ))
                {
                    name.pop_back();
                    mvwaddstr(stdscr, 3, 1+ strlen(lang.getLine(7)), name.c_str());
                    wclrtoeol(stdscr);
                    mvwaddch(stdscr, 3, getmaxx(stdscr) - 1, '|');
                    mvwaddch(stdscr, 3, 1 + strlen(lang.getLine(7)) + strlen(name.c_str()), '_');
                    refresh();
                }
            }
        }
        while(opt != 10); // 10 = Enter

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
    
    WINDOW *wmap, *wcmd, *wlog;
    
    wmap = subwin(stdscr, 20, 40, 0, 0);
    wcmd = subwin(stdscr, 20, 40, getmaxy(wmap), 0);
    wlog = subwin(stdscr, MAP_MAXY, MAP_MAXX-getmaxx(wmap), 0, getmaxx(wmap));
    clear();

    do  //Main Game Loop
    {
        ostringstream sturn;
        turn++;

        {
            drawBox(wmap);
            drawMap(wmap);
            drawBox(wcmd);
            drawBox(wlog);
        }
        
        mvwaddstr(wcmd, 1, 1, lang.getLine(11));
        sturn << turn;
        mvwaddstr(wcmd, 1, strlen(lang.getLine(11)) + 1, sturn.str().c_str());
        wrefresh(wcmd);
        
        do  //Phase 1: Command parsing and Processing
        {
            cmd.clear();
            mvwaddstr(wcmd, getmaxy(wcmd)-3, 1, lang.getLine(12));
            wclrtoeol(wcmd);
            mvwaddch(wcmd, getmaxy(wcmd)-3, getmaxx(wcmd)-1, '|');
            mvwaddch(wcmd, getmaxy(wcmd)-3, 1 + strlen(lang.getLine(12)), '_');
            wrefresh(wcmd);
            
            do
            {
                opt = getch();
                
                if((opt == ' ') || (opt >= '0' && opt <= '9') || (opt >= 'A' && opt <= 'Z') || (opt >= 'a' && opt <= 'z'))
                {
                    if(cmd.size() < 20)
                    {
                        if(!(cmd.empty() && opt == ' '))
                        {
                            cmd.push_back(opt);
                            mvwaddstr(wcmd, getmaxy(wcmd)-3, 1 + strlen(lang.getLine(12)), cmd.c_str());
                            mvwaddch(wcmd, getmaxy(wcmd)-3, 1 + strlen(lang.getLine(12)) + strlen(cmd.c_str()), '_');
                            wrefresh(wcmd);
                        }
                    }
                }
                else if(opt == 8 || opt == 127)
                {
                    if(!(cmd.empty()))
                    {
                        cmd.pop_back();
                        mvwaddstr(wcmd, getmaxy(wcmd)-3, 1 + strlen(lang.getLine(12)), cmd.c_str());
                        wclrtoeol(wcmd);
                        mvwaddch(wcmd, getmaxy(wcmd)-3, getmaxx(wcmd)-1, '|');
                        mvwaddch(wcmd, getmaxy(wcmd)-3, 1 + strlen(lang.getLine(12)) + strlen(cmd.c_str()), '_');
                        wrefresh(wcmd);
                    }
                }
            }
            while(opt != 10);   //Key Enter
            
            if(cmd.empty())
            {
                mvwaddstr(wcmd, getmaxy(wcmd)-2, 1, lang.getLine(13));
            }
            else
            {
                switch(phase)
                {
                    case 1:
                        if(cmd != "config")
                            mvwaddstr(wcmd, getmaxy(wcmd) - 2, 2, "Not OK!");
                        else
                            parseCmd(cmd, lang, wcmd);
                        break;
                    case 2:
                        if(cmd == "config")
                            mvwaddstr(wcmd, getmaxy(wcmd) - 2, 2, "Not OK!");
                        else
                            parseCmd(cmd, lang, wcmd);
                }
            }
        }
        while(cmd != lang.getCmd(2) && cmd != lang.getCmd(19));
        
        if(cmd == lang.getCmd(19))
            break;
        
        //IMPLEMENT PHASE 2 HERE
        /*
         
         */
    }
    while(cmd != lang.getCmd(19));
    
    delwin(wmap);
    delwin(wcmd);
    delwin(wlog);
}