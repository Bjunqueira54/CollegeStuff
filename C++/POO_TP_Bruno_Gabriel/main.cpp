#include "headers.h"
#include "Functions.h"
#include "Player.h"
#include "Language.h"

using namespace std;

int main(int argc, char** argv)
{
    initscr();
    noecho();
    resizeterm(30, 100);
    
    char opt;
    string name = "";
    string cmd = "";
    string aux;
    int turn=0;
    ostringstream sturn;
    
    /* ==== PEDE E VERIFICA A LINGUAGEM ==== */
    while(opt != '1' && opt != '2')
    {
        mvwaddstr(stdscr, 1, 1, "Portugues - 1\n English - 2\n\n ->");
        refresh();
        opt = getch();
    }
    
    clear();
    refresh();
    Language lang((opt == '1') ? 1 : 2);
    
    mvwaddstr(stdscr, 9, getCenter(lang.getLine(1)), lang.getLine(1));
    mvwaddstr(stdscr, 11, getCenter(lang.getLine(0)), lang.getLine(0));
        
    refresh();
    getch();
    clear();

    while(1)
    {
        mvwaddstr(stdscr, 1, 1, lang.getLine(6));
        mvwaddstr(stdscr, 3, 1, lang.getLine(7));
        refresh();
        
        opt = 0;
        
        while(opt != KEY_ENTER)
        {
            opt = getch();
            
            if((opt == ' ') || (opt >= '0' && opt <= '9') || (opt >= 'A' && opt <= 'Z') || (opt >= 'a' && opt <= 'z'))
            {
                name.push_back(opt);
                mvwaddstr(stdscr, 3, strlen(lang.getLine(7)) + 1, name.c_str());
                refresh();
            }
            else if(opt == 8 || opt == 127)
            {
                if(!( name.empty() ))
                {
                    name.pop_back();
                    mvwaddch(stdscr, 3, strlen(lang.getLine(7)) + strlen(name.c_str()) + 1, ' ');
                    mvwaddstr(stdscr, 3, strlen(lang.getLine(7)) + 1, name.c_str());
                    refresh();
                }
            }
            else if(opt == KEY_ENTER || opt == 10 || opt == '\n') break;
        }
        
        if(name.empty())
            mvwaddstr(stdscr, 1, 2, lang.getLine(8));
        else
            break;
    }
    
    Player player(name);
    
    clear();
    
    aux.clear();
    aux = lang.getLine(10);
    aux += name;

    /*mvwaddstr(stdscr, 9, getCenter(lang.getLine(10)), lang.getLine(10));
    mvwaddstr(stdscr, 9, (28 + strlen(lang.getLine(10))), name.c_str());*/
    mvwaddstr(stdscr, 9, getCenter(aux), aux.c_str());
    mvwaddstr(stdscr, 11, getCenter(lang.getLine(0)), lang.getLine(0));

    refresh();
    getch();
    
    do
    {
        sturn.str().clear();
        turn++;
        clear();
        mvwaddstr(stdscr, 1, 1, lang.getLine(11));
        sturn << turn;
        mvwaddstr(stdscr, 1, strlen(lang.getLine(11)) + 1, sturn.str().c_str());
        refresh();
        
        do    //Phase 1: Command reading and execution
        {
            cmd.empty();
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
                        mvwaddstr(stdscr, 2, strlen(lang.getLine(12)) + 1, cmd.c_str());
                        refresh();
                    }
                }
                else if(opt == 8 || opt == 127)
                {
                    if(!( cmd.empty() ))
                    {
                        cmd.pop_back();
                        mvwaddch(stdscr, 2, strlen(lang.getLine(12)) + strlen(cmd.c_str()), ' ');
                        mvwaddstr(stdscr, 2, strlen(lang.getLine(12)), cmd.c_str());
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
    
    endwin();
    return 0;
}