#include "headers.h"
#include "Functions.h"
#include "Player.h"
#include "Language.h"

using namespace std;

int main(int argc, char** argv)
{
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
    Language lang((opt == '1') ? 1 : 2);
    
    mvwaddstr(stdscr, 9, 25, lang.getLine(1));
    mvwaddstr(stdscr, 11, 23, lang.getLine(0));
        
    refresh();
    getch();
    clear();
    
    string name = "";
    
    while(1)
    {
        mvwaddstr(stdscr, 0, 0, lang.getLine(6));
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
    
    string cmd = "";
    
    Player player(name);
    
    clear();

    mvwaddstr(stdscr, 9, 28, lang.getLine(10));
    mvwaddstr(stdscr, 9, 49, name.c_str());
    mvwaddstr(stdscr, 11, 20, lang.getLine(0));


    refresh();
    getch();
    clear();
    
    int turn=0;
    ostringstream sturn;
    
    while(cmd != "sair" && cmd != "exit")
    {
        cmd = "";
        turn++;
        clear();
        mvwaddstr(stdscr, 1, 1, lang.getLine(11));
        sturn << turn;
        mvwaddstr(stdscr, 1, 8, sturn.str().c_str());
        refresh();
        
        while(cmd != "prox" && cmd != "sair" && cmd != "exit")    //Phase 1: Command reading and execution
        {
            mvwaddstr(stdscr, 1, 1, lang.getLine(12));
            
            refresh();
            getline(cin, cmd);
            if(cmd == "") 
            {
                mvwaddstr(stdscr, 1, 1, lang.getLine(13));
                refresh();
                getch();
            }
            //else
            clear();
            //parseCmd();
        }
        
        if(cmd != "sair" && cmd != "exit")
        {
            //Phase 2: Player command processing

            //Phase 3: AI Movement

            //Phase 4: Battle procedure

            //Phase 5: Map Events

            //Phase 6: Enemy AI Ship spawn
        }
    }
    endwin();
    return 0;
}