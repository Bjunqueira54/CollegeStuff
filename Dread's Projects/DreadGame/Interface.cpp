#include "Interface.h"

void Interface::WelcomeScreen()
{
    ClearScreen();
    cout << "Welcome to DreadGame (aka. MonsterSlayer)" << endl;
    getchar();
}

void Interface::PrintMainMenu()
{
    ClearScreen();
    cout << "1 - Start Game" << endl;
    cout << "2 - Show Credits" << endl;
    cout << "0 - Exit Game" << endl;
}

void Interface::PrintBattleMenu(string player_Name, int player_HP, int monster_HP)
{
    ClearScreen();
    cout << "1 - Attack" << endl;
    cout << "2 - Special Attack" << endl;
    cout << "3 - Heal" << endl;
    cout << "4 - Block" << endl;
    cout << "0 - Run Away" << endl;
}

void Interface::ShowCredits()
{
    ClearScreen();
    cout << "Head Developer: Bruno 'GothicDread' Junqueira" << endl;
    cout << "That's all folks!" << endl;
    getchar();
}

void Interface::Victory()
{
    ClearScreen()
    cout << "You've won! Congratulations" << endl;
    getchar();
}

void Interface::Defeat()
{
    ClearScreen();
    cout << "You Died!" << endl;
    cout << "Git Gud" << endl;
    getchar();
}

void Interface::ShowStats(string player_Name, int player_HP, int monster_HP)
{
    cout << player_Name << " has " << player_HP << " and the monster has " << monster_HP << endl;
}

string Interface::getString()
{
    string os;
    getline(cin, os);
    return os;
}

void Interface::ClearScreen()
{
    system("clear");
}

Interface::~Interface() {}