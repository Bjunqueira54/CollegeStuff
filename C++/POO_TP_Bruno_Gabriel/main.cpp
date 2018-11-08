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
        /*char opti[5];
        while(1)
        {
            opt = getch();
            sprintf(opti, "%i", opt);
            clear();
            mvwaddstr(stdscr, 5, 5, opti);
            refresh();
        }*/
        int x=0;
        
        while(1)
        {
            if(x == 15)
                x--;
            else
            {
                opt = getch();
                if(opt == 10)   //Tecla Enter
                    break;
                else if((opt == KEY_BACKSPACE) || (opt == KEY_DC)) //Tecla Backspace
                {
                    if(x>0)
                    {
                        mvwaddch(stdscr, 3, --x, ' ');
                        tempname[x] = '\0';
                        //move(3, --x);
                        refresh();
                    }
                }
                else if( (opt == ' ') ||             //Se a tecla for espaço...
                    (opt >= '0' && opt <= '9') ||     //... ou se o código ASCII da tecla estiver entre 0-9...
                    (opt >= 'A' && opt <= 'Z') ||     //... ou se o código ASCII da tecla estiver entre A-Z...
                    (opt >= 'a' && opt <= 'z')   )   //... ou se o código ASCII da tecla estiver entre a-z.
                {
                    mvwaddch(stdscr, 3, x, opt);
                    tempname[x] = opt;
                    refresh();
                    x++;
                }
                else
                    if(x>0)
                        move(3,--x);
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

