#ifndef INTERFACE_H
#define INTERFACE_H

#include "includes.h"
#include "Game.h"

class Interface
{
    Game* game;
    bool Exit;
    
public:
    Interface();
    Interface(const Interface& orig) = delete;
    
    void Init();
    
    virtual ~Interface();
    
private:
    
    void ClearScreen();
    void OnUserCreate();
    void OnUserUpdate();
    
    void drawUserInterface();
};

#endif