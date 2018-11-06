#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
    //drawUI(20,40); //Pending nCurses implementation
    cout << "\nBem vindo a Cid Meier's Pirates!" << endl;  // alterei o nome de proposito
    cout << "(Pressiona qualquer botao para continuar)" << endl;
    
    string name;
    while(name == "")
    {
        cout << "\nIntroduza o seu nome: ";
        getline(cin, name);
        if(name == "") 
        {
            cout << "\nNome invalido!";
        }
    }
    
    int turn=0;
    string cmd = "";
    
    Player player(name);
    
    cout << "\nBoa sorte marinheiro " << name << "!" << endl;
    cout << "(Pressiona qualquer botao para continuar)" << endl;
    
    while(cmd != "sair")
    {
        cmd = "";
        turn++;
        cout << "\nTurno " << turn << endl;
        
        while(cmd != "prox" && cmd != "sair")    //Phase 1: Command reading and execution
        {
            //drawUI(); //Pending nCurses implementation
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
