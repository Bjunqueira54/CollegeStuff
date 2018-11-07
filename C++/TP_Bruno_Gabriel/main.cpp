#include "main.h"

using namespace std;

void StartGame()
{
    if(system("cls") == 32512)
        system("clear");
    
    cout << "Coming soom(tm)..." << endl;
}

int main(int argc, char** argv)
{
    cout << "Welcome to Wannabe Sid Meyer's Pirates!" << endl;
    
    cout << "1 - Start Game" << endl;
    cout << "2 - Exit Game" << endl;
    
    int option;
    
    cin >> option;
    
    switch(option)
    {
        case 1:
            StartGame();
            break;
        case 2:
            return 0;
    }
    return 0;
}

