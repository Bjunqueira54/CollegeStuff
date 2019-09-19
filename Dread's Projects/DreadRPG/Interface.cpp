#include "Interface.h"

Interface::Interface() {}

Interface::Interface(const Interface& orig) {}

char Interface::getChar()
{
    return std::getchar();
}

string Interface::getPlayerName()
{
    string name;
    ClearScreen();
    cout << "What's your name?" << endl;
    cout << "Name: ";
    
    getline(cin, name);
    
    return name;
}

void Interface::Tutorial()
{
    ClearScreen();
    cout << "To be added later" << endl;
    getChar();
    ClearScreen();
}

void Interface::WelcomeScreen()
{
    cout << "Welcome to DreadRPG" << endl;
    getchar();
}

void Interface::VictoryScreen()
{
    Interface::ClearScreen();
    cout << "You have won the battle" << endl;
}

void Interface::DefeatScreen()
{
    Interface::ClearScreen();
    cout << "You have been defeated" << endl;
}

void Interface::MainMenu()
{
    Interface::ClearScreen();
    cout << "1 - Start Game" << endl;
    cout << "2 - Tutorial" << endl;
    cout << "0 - Exit Game" << endl;
}

void Interface::BattleMenu()
{
    ClearScreen();
    cout << "1 - Attack" << endl;
    cout << "2 - Block" << endl;
    cout << "3 - Heal" << endl;
    cout << "4 - Special" << endl;
    cout << "0 - Run" << endl;
}

//I know this is fucking disgusting
//but it's 1:30AM and I got classes in the morning
void Interface::ClearScreen()
{
    system("clear");
}

Interface::~Interface() {}