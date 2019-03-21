#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"

class Interface
{
    
    
public:
    
    Interface();
    Interface(const Interface& orig) = delete;
    
    //Draws the main menu for the game.
    //Note: for in-game combat options, use DrawCombatMenu()
    void DrawMainMenu();
    
    //Draws the in-game Combat Options Menu
    //Note: use DrawMainMenu() for out-of-game main menu
    void DrawCombatMenu();
    
    //Gets a character from the user and returns the
    //ASCII int value for it
    int getOpt();
    
    virtual ~Interface();
};

#endif