#include "headers.h"
#include "Functions.h"
#include "Player.h"
#include "Language.h"

using namespace std;

int main(int argc, char** argv)
{
    initscr();
    noecho();
    //drawUI(20,40);
    
    Language langP(1),langE(2);
    char opt;
    
    /* ==== PEDE E VERIFICA A LINGUAGEM ==== */
    while(opt != '1' && opt != '2')
    {
        mvwaddstr(stdscr, 1, 1, "Portugues - 1\n English - 2\n\n ->");
        refresh();
        opt = getch();
        clear();
    }
    
    if(opt == '1')
    {
        mvwaddstr(stdscr, 9, 25, langP.getLine()[1].c_str());
        mvwaddstr(stdscr, 11, 23, langP.getLine()[0].c_str());
    }
    else if(opt == '2')
    {
        mvwaddstr(stdscr, 9, 25, langE.getLine()[1].c_str());
        mvwaddstr(stdscr, 11, 20, langE.getLine()[0].c_str());
    }
    refresh();
    getch();
    
    string name;
    while(name == "")
    {
        clear();
        if(opt == '1')
            mvwaddstr(stdscr, 1, 1, langP.getLine()[6].c_str());
        else if(opt == '2')
            mvwaddstr(stdscr, 1, 1, langE.getLine()[6].c_str());
        
        refresh();
        echo();
        getline(cin, name);
        
        if(name == "") 
        {
            clear();
            if(opt == '1')
                mvwaddstr(stdscr, 1, 1, langP.getLine()[7].c_str());
            else if(opt == '2')
                mvwaddstr(stdscr, 1, 1, langE.getLine()[7].c_str());
            
            refresh();
            getch();
        }
    }
    
    int turn=0;
    string cmd = "";
    
    Player player(name);
    
    clear();
    if(opt == '1')
    {
        mvwaddstr(stdscr, 9, 28, langP.getLine()[9].c_str());
        mvwaddstr(stdscr, 9, 49, name.c_str());
        mvwaddstr(stdscr, 11, 20, langP.getLine()[0].c_str());
    }
    else if(opt == '2')
    {
        mvwaddstr(stdscr, 9, 28, langE.getLine()[9].c_str());
        mvwaddstr(stdscr, 9, 49, name.c_str());
        mvwaddstr(stdscr, 11, 20, langE.getLine()[0].c_str());
    }
    refresh();
    getch();
    clear();
    
    while(cmd != "sair" && cmd != "exit")
    {
        cmd = "";
        turn++;
        clear();
        if(opt == '1')
            mvwaddstr(stdscr, 1, 1, langP.getLine()[10].c_str());
        else if(opt == '2')
            mvwaddstr(stdscr, 1, 1, langE.getLine()[10].c_str());
        
        //mvwaddstr(stdscr, 1, 8, turn); /* erro aqui no turn */
        refresh();
        
        while(cmd != "prox" && cmd != "sair" && cmd != "exit")    //Phase 1: Command reading and execution
        {
            if(opt == '1')
                mvwaddstr(stdscr, 1, 1, langP.getLine()[11].c_str());
            else if(opt == '2')
                mvwaddstr(stdscr, 1, 1, langE.getLine()[11].c_str());
            
            refresh();
            getline(cin, cmd);
            if(cmd == "") 
            {
                if(opt == '1')
                    mvwaddstr(stdscr, 1, 1, langP.getLine()[12].c_str());
                else if(opt == '2')
                    mvwaddstr(stdscr, 1, 1, langE.getLine()[12].c_str());
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

