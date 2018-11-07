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
    
    mvwaddstr(stdscr, 9, 25, lang.getLine()[1].c_str());
    mvwaddstr(stdscr, 11, 23, lang.getLine()[0].c_str());
        
    refresh();
    getch();
    clear();
    
    string name="";
    char tempname[20] = "";

    while(name == "")
    {
        mvwaddstr(stdscr, 1, 1, lang.getLine()[6].c_str());
        move(3,1);
        refresh();
        
        for(int x=0; ( opt = getch() ) != 10 || ( opt = getch() ) != KEY_ENTER; x++)
        {
            if(x == 15)
                x--;
            else
            {
                if( (opt == 32) ||                  //Se a tecla for espaço...
                    (opt >= 48 && opt <= 57) ||     //... ou se o código ASCII da tecla estiver entre 0-9...
                    (opt >= 65 && opt <= 90) ||     //... ou se o código ASCII da tecla estiver entre A-Z...
                    (opt >= 97 && opt <= 122)   )   //... ou se o código ASCII da tecla estiver entre a-z.
                {
                    mvwaddch(stdscr, 3, x+1, opt);
                    tempname[x] = opt;
                    refresh();
                }
                else
                    x--;
            }
        }
        
        name = tempname;
        
        if(name == "") 
        {
            clear();
            mvwaddstr(stdscr, 1, 2, lang.getLine()[7].c_str());
            name = "";
            for(int i=0; i<20; i++)
                tempname[i] = '\0';
        }
    }
    
    int turn=0;
    string cmd = "";
    
    Player player(name);
    
    clear();

    mvwaddstr(stdscr, 9, 28, lang.getLine()[9].c_str());
    mvwaddstr(stdscr, 9, 49, name.c_str());
    mvwaddstr(stdscr, 11, 20, lang.getLine()[0].c_str());


    refresh();
    getch();
    clear();
    
    while(cmd != "sair" && cmd != "exit")
    {
        cmd = "";
        turn++;
        clear();
        mvwaddstr(stdscr, 1, 1, lang.getLine()[10].c_str());
        
        //mvwaddstr(stdscr, 1, 8, turn); /* erro aqui no turn */
        refresh();
        
        while(cmd != "prox" && cmd != "sair" && cmd != "exit")    //Phase 1: Command reading and execution
        {
            mvwaddstr(stdscr, 1, 1, lang.getLine()[11].c_str());
            
            refresh();
            getline(cin, cmd);
            if(cmd == "") 
            {
                mvwaddstr(stdscr, 1, 1, lang.getLine()[12].c_str());
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

