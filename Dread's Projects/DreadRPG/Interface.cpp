#include "Interface.h"

const char Interface::getChar()
{
    char c;
    c = std::getchar();
    return c;
}

const string Interface::getString()
{
    string s;
    getline(std::cin, s);
    return s;
}

void Interface::PrintBattleMenu()
{
    ClearScreen();
    cout << "1 - Attack" << endl;
    cout << "2 - Special Attack" << endl;
    cout << "3 - Defend" << endl;
    cout << "4 - Heal" << endl;
    cout << "0 - Run" << endl;
}

void Interface::PrintMainMenu()
{
    ClearScreen();
    cout << "1 - Start Game" << endl;
    cout << "2 - Help Section" << endl;
    cout << "3 - Credits" << endl;
    cout << "0 - Exit Game" << endl;
}

void Interface::PrintCredits()
{
    ClearScreen();
    cout << "Creator: Bruno 'GothicDread' Junqueira" << endl;
    std::getchar();
}

void Interface::PrintHelpSection()
{
    ClearScreen();
    cout << "Nothing yet" << endl;
    std::getchar();
}

//leave like this for now
//change later
void Interface::ClearScreen()
{
    system("clear");
}

Interface::~Interface() {}