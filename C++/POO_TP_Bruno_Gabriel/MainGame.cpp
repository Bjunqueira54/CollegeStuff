#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

void MainGameLoop(Language lang)
{
    int turn=0;
    char opt;
    string name, cmd, aux;
    
    do
    {
        clear();
        mvwaddstr(stdscr, 1, 1, lang.getLine(6));
        mvwaddstr(stdscr, 3, 1, lang.getLine(7));
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
                    mvwaddstr(stdscr, 3, strlen(lang.getLine(7)) + 1, name.c_str());
                    refresh();
                }
            }
            else if(opt == 8 || opt == 127) // 8 = Backspace, 127 = Delete
            {
                if(!( name.empty() ))
                {
                    name.pop_back();
                    mvwaddch(stdscr, 3, strlen(lang.getLine(7)) + strlen(name.c_str()) + 1, ' ');
                    mvwaddstr(stdscr, 3, strlen(lang.getLine(7)) + 1, name.c_str());
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

    mvwaddstr(stdscr, 9, getCenter(aux), aux.c_str());
    mvwaddstr(stdscr, 11, getCenter(lang.getLine(0)), lang.getLine(0));

    refresh();
    getch();
    
    WINDOW *wmap, *wcmd, *wlog;
    
    wmap = newwin(20, 40, 1, 1);
    wcmd = newwin(20, 40, MAP_MAXY-getmaxy(wmap), 1);
    wlog = newwin(MAP_MAXY, MAP_MAXX-getmaxx(wmap), 1, MAP_MAXX-getmaxx(wmap));
    
    drawBox(wmap);
    drawBox(wcmd);
    drawBox(wlog);
    getch();

    do
    {
        ostringstream sturn;
        turn++;
        clear();
        mvwaddstr(stdscr, 1, 1, lang.getLine(11));
        sturn << turn;
        mvwaddstr(stdscr, 1, strlen(lang.getLine(11)) + 1, sturn.str().c_str());
        refresh();

        do    //Phase 1: Command reading and execution
        {
            cmd.clear();
            mvwaddstr(stdscr, 2, 1, lang.getLine(12));
            refresh();

            do
            {
                opt = getch();

                if((opt == ' ') || (opt >= '0' && opt <= '9') || (opt >= 'A' && opt <= 'Z') || (opt >= 'a' && opt <= 'z'))
                {
                    if(!(cmd.empty() && opt == ' '))
                    {
                        cmd.push_back(opt);
                        mvwaddstr(stdscr, 2, 1 + strlen(lang.getLine(12)), cmd.c_str());
                        refresh();
                    }
                }
                else if(opt == 8 || opt == 127)
                {
                    if(!(cmd.empty()))
                    {
                        mvwaddch(stdscr, 2, strlen(lang.getLine(12)) + strlen(cmd.c_str()), ' ');
                        cmd.pop_back();
                        mvwaddstr(stdscr, 2, 1 + strlen(lang.getLine(12)), cmd.c_str());
                        refresh();
                    }
                }
            }
            while(opt != KEY_ENTER && opt != 10 && opt != '\n');

            if(cmd.empty()) 
            {
                mvwaddstr(stdscr, 3, 1, lang.getLine(13));
                refresh();
                getch();
            }
            else
            {
                parseCmd(cmd, lang);
                mvwaddstr(stdscr, 2, 1, "                                       "); //just for now;
            }
        }
        while(cmd != lang.getCmd(2) && cmd != lang.getCmd(19));

        if(cmd != "sair" && cmd != "exit")
        {
            //Phase 2: Player command processing

            //Phase 3: AI Movement

            //Phase 4: Battle procedure

            //Phase 5: Map Events

            //Phase 6: Enemy AI Ship spawn
        }
    }
    while(cmd != lang.getCmd(19));
}