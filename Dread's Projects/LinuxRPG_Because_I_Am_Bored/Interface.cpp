#include "Interface.h"

Interface::Interface() {}

Interface::Interface(const Interface& orig) {}

void Interface::WelcomeScreen()
{
    cout << "Welcome to 'yet another fucking RPG' by GothicDread" << endl;
}

void Interface::ClearScreen()
{
    cout << "\e[2J\e[H";
}


Interface::~Interface() {}