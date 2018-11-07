#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
    initscr();
    noecho();
    //keypad(stdscr, TRUE);
    //drawUI(20,40);
    
    mvwaddstr(stdscr, 9, 25, "Bem vindo a Cid Martin's Pirates");
    mvwaddstr(stdscr, 11, 20, "(Pressione qualquer botao para continuar)");
    getch();
    clear();
    
    string name;
    while(name == "")
    {
        clear();
        mvwaddstr(stdscr, 1, 1, "Introduza o seu nome: ");
        getline(cin, name);
        if(name == "") 
        {
            clear();
            mvwaddstr(stdscr, 1, 1, "Nome invalido!");
            getch();
        }
    }
    
    int turn=0;
    string cmd = "";
    
    Player player(name);
    
    clear();
    mvwaddstr(stdscr, 9, 28, "Boa sorte marinheiro ");
    //mvwaddstr(stdscr, 9, 40, name);
    mvwaddstr(stdscr, 11, 20, "(Pressione qualquer botao para continuar)");
    getch();
    clear();
    
    while(cmd != "sair")
    {
        cmd = "";
        turn++;
        clear();
        cout << "\nTurno " << turn << endl;
        
        while(cmd != "prox" && cmd != "sair")    //Phase 1: Command reading and execution
        {
            //drawUI(); //Pending nCurses implementation
            cout << "Comando: ";
            getline(cin, cmd);
            if(cmd == "") 
            {
                cout << "Comando não especificado" << endl;
                getch();
            }
            //else
            clear();
            //parseCmd();
        }
        
        if(cmd != "sair")
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

