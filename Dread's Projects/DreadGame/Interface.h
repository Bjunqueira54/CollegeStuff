#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"
#include <iostream>

class Interface {
public:

    Interface() = delete;
    Interface(const Interface& orig) = delete;

    static void WelcomeScreen();
    static void PrintMainMenu();
    static void PrintBattleMenu(string player_Name, int player_HP, int monster_HP);
    static void ShowCredits();

    static void Victory();
    static void Defeat();
    
    static void ShowStats(string player_Name, int player_HP, int monster_HP);
    
    static char getChar() { return getchar(); }
    static string getString();
    
    virtual ~Interface();
    
private:
    
    static void ClearScreen();
};

#endif