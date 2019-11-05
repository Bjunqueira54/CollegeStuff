#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"
#include "Game.h"

class Interface
{
    bool Exit;
    Game* game;
    
public:
    Interface();
    Interface(const Interface& orig) = delete;
    
    void Init();
    void StartGame();
    void MainMenu();
    void Tutorial();
    void Credits();
    
    virtual ~Interface();
    
private:
    
    void ClearScreen();
};

#endif