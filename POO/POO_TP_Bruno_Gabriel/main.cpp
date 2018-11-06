#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
    Consola::setScreenSize(50,60);
    drawUI(20,40);
    Consola::gotoxy(10,15);
    cout << "\nBem vindo a Cid Meier's Pirates!" << endl;  // alterei o nome de proposito
    cout << "(Pressiona qualquer botao para continuar)" << endl;
    Consola::getch();
    
    string name;
    while(name == "")
    {
        Consola::clrscr();
        cout << "\nIntroduza o seu nome: ";
        getline(cin, name);
        if(name == "") 
        {
            Consola::clrscr();
            cout << "\nNome invalido!";
            Consola::getch();
        }
    }
    
    int turn=0;
    string cmd = "";
    
    Player player(name);
    
    Consola::clrscr();
    cout << "\nBoa sorte marinheiro " << name << "!" << endl;
    cout << "(Pressiona qualquer botao para continuar)" << endl;
    Consola::getch();
    
    while(cmd != "sair")
    {
        Consola::clrscr();
        cmd = "";
        turn++;
        cout << "\nTurno " << turn << endl;
        
        while(cmd != "prox" && cmd != "sair")    //Phase 1: Command reading and execution
        {
            //drawUI();
            cout << "Comando: ";
            getline(cin, cmd);
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
    return 0;
}

