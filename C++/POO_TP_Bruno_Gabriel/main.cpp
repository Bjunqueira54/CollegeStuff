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
    
    Language lang(1);
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
        mvwaddstr(stdscr, 9, 25, "Bem vindo a Cid Martin's Pirates");
        mvwaddstr(stdscr, 11, 20, "(Pressione qualquer botao para continuar)");
    }
    else
    {
        mvwaddstr(stdscr, 9, 25, "Bem vindo a Cid Martin's Pirates");
        mvwaddstr(stdscr, 11, 20, "(Pressione qualquer botao para continuar)");
    }
    refresh();
    getch();
    
    string name;
    while(name == "")
    {
        clear();
        if(opt == '1')
            mvwaddstr(stdscr, 1, 1, "Introduza o seu nome: ");
        else
            mvwaddstr(stdscr, 1, 1, "Introduza o seu nome: ");
        
        refresh();
        echo();
        getline(cin, name);
        
        if(name == "") 
        {
            clear();
            if(opt == '1')
                mvwaddstr(stdscr, 1, 1, "Nome invalido!");
            else
                mvwaddstr(stdscr, 1, 1, "Nome invalido!");
            
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
        mvwaddstr(stdscr, 9, 28, "Boa sorte marinheiro ");
        mvwaddstr(stdscr, 9, 49, name.c_str());
        mvwaddstr(stdscr, 11, 20, "(Pressione qualquer botao para continuar)");
    }
    else
    {
        mvwaddstr(stdscr, 9, 28, "Boa sorte marinheiro ");
        mvwaddstr(stdscr, 9, 49, name.c_str());
        mvwaddstr(stdscr, 11, 20, "(Pressione qualquer botao para continuar)");
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
            mvwaddstr(stdscr, 1, 1, "Turno ");
        else 
            mvwaddstr(stdscr, 1, 1, "Turno ");
        
        mvwaddstr(stdscr, 1, 8, turn.c_str());
        refresh();
        
        while(cmd != "prox" && cmd != "sair" && cmd != "exit")    //Phase 1: Command reading and execution
        {
            if(opt == '1')
                mvwaddstr(stdscr, 1, 1, "Comando: ");
            else 
                mvwaddstr(stdscr, 1, 1, "Comando: ");
            
            refresh();
            getline(cin, cmd);
            if(cmd == "") 
            {
                if(opt == '1')
                    mvwaddstr(stdscr, 1, 1, "Comando não especificado");
                else 
                    mvwaddstr(stdscr, 1, 1, "Comando não especificado");
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

