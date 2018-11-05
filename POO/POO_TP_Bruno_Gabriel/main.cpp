#include "headers.h"
#include "Functions.h"
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
    Consola::setScreenSize(45, 40);
    cout << "Welcome to Sid Meyer's Pirates! Wannabe" << endl;
    
    string name;
    cout << "Enter your name: ";
    cin >> name;
    
    int turno=0;
    string cmd = "";
    
    Player player(name);
    
    while(1)
    {
        /*while(cmd != "prox");
        {
            Consola::gotoxy()
        }*/
        turno++;
    }
    return 0;
}

