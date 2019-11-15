#include "Interface.h"

Interface::Interface()
{
    Exit = false;
}

void Interface::Init()
{
    OnUserCreate();
    
    do
    {
        OnUserUpdate();
    }
    while(!Exit);
}

void Interface::ClearScreen()
{
    system("clear");
}

void Interface::OnUserCreate()
{
    cout << "Welcome to Dread Game\n" << endl;
    cout << "What's your name?" << endl;
    cout << "Name: ";
    
    string name;
    
    cin >> name;
    
    cout << "Welcome " << name << endl;
    cout << "Good Luck and Have Fun!" << endl;
    
    game = new Game(name);
}

void Interface::OnUserUpdate()
{
    drawUserInterface();
    
    char input;
    
    cin.get(input);
    
    game->UserInput(input);
}

void Interface::drawUserInterface()
{
    if(game->getGameState().compare("MainMenuState"))
    {
        cout << "1 - Start Game" << endl;
        cout << "2 - Tutorial" << endl;
        cout << "3 - Credits" << endl;
        cout << "0 - Exit Game" << endl;
    }
    else if (game->getGameState().compare("BattleState"))
    {
        cout << "1 - Attack" << endl;
        cout << "2 - Defend" << endl;
        cout << "3 - Heal" << endl;
        cout << "4 - Special" << endl;
        cout << "0 - Give Up" << endl;
    }
}

Interface::~Interface()
{
    delete game;
}
