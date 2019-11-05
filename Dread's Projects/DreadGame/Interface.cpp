#include "Interface.h"

Interface::Interface()
{
    Exit = false;
}

void Interface::Init()
{
    cout << "Welcome to Dread's Console Game"<< endl;
    
    getchar();
    
    MainMenu();
}

void Interface::MainMenu()
{
    char choice;
    
    while(!Exit)
    {
        ClearScreen();
        cout << "1 - Start Game" << endl;
        cout << "2 - Tutorial" << endl;
        cout << "3 - Credits" << endl;
        cout << "0 - Exit Game" << endl;

        char choice;

        do
        {
            choice = getchar();
        }
        while(!(choice >= '1' && choice <= '3') && (choice != '0'));
        
        switch(choice)
        {
            case '1':
                StartGame();
                break;
            case '2':
                Tutorial();
                break;
            case '3':
                Credits();
                break;
            case '0':
                Exit = true;
                break;
            default:
                cout << "How did you get in here?" << endl;
                break;
        }
    }
}

void Interface::StartGame()
{
    ClearScreen();
    
    cout << "What's your name?" << endl;
    cout << "Name: ";
    string name;
    cin >> name;
    
    ClearScreen();
    
    cout << "Good Luck " << name << endl;
    
    getchar();
    
    game = new Game(name);
}

void Interface::Tutorial()
{
    
}

void Interface::Credits()
{
    
}


void Interface::ClearScreen()
{
    system("clear");
}

Interface::~Interface()
{
    delete game;
}
