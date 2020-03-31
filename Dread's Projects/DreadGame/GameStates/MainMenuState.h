#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../includes.h"
#include "GameState.h"

class MainMenuState: public GameState
{
public:
    MainMenuState() = delete;
    MainMenuState(const MainMenuState& orig) = delete;
    MainMenuState(GameData*);
    
    const virtual string getStateName() { return "MainMenuState"; }
    
    virtual ~MainMenuState();
};

#endif