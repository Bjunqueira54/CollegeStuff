#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
    Consola::setScreenSize(45, 40);
    cout << "Bem vindo a mistura de Sid Meyer's Civilization + Pirates!... versao consola!" << endl;
    
    string name;
    cout << "Qual o seu nome: ";
    getline(cin, name);
    
    int turn=0;
    string cmd = "";
    
    Player player(name);
    
    cout << "Boa Sorte e Diverte-te " << name << "!" << endl;
    cout << "(Pressiona qualquer butao para continuar... menos o de desligar)" << endl;
    Consola::getch();

    while(cmd != "sair")
    {
        Consola::clrscr();
        cmd = "";
        turn++;
        cout << "Turno " << turn << endl;
        
        while(cmd != "prox" && cmd != "sair")    //Phase 1: Command reading and execution
        {
            //drawUI();
            cout << "Command: ";
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

