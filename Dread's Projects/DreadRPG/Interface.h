#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"

class Interface
{
    
public:
    Interface() = delete;
    Interface(const Interface& orig) = delete;
    
    static const char getChar();
    static const string getString();
    
    static void PrintMainMenu();
    static void PrintBattleMenu();
    
    static void PrintCredits();
    static void PrintHelpSection();
    
    static void GetNameScreen();
    
    virtual ~Interface();
    
private:
    
    static void ClearScreen();
};

#endif