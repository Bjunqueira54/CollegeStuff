#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState: public GameState
{
    
public:
    
    MainMenuState();
    MainMenuState(const MainMenuState& orig) = delete;
    
    virtual ~MainMenuState();

private:

};

#endif