#include "Interface.h"

Interface::Interface() {}

Interface::Interface(const Interface& orig) {}

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

//I know this is fucking disgusting
//but it's 1:30AM and I got classes in the morning
void Interface::ClearScreen()
{
#if defined(__CYGWIN__) && !defined(_WIN32)
    system("cls");
#elif defined(__linux__)
    system("clear");
#endif
}

Interface::~Interface() {}