#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"

class Interface
{
public:

    Interface();
    Interface(const Interface& orig);
    
    static void WelcomeScreen();
    static void MainMenu();
    static void VictoryScreen();
    static void DefeatScreen();
    
    static void ClearScreen();

    virtual ~Interface();
};

#endif