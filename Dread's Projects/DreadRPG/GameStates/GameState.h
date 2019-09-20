#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../includes.h"
#include "../GameData/GameData.h"
#include "../Interface.h"

class GameState
{
    GameData* gData;
    
public:
    GameState() = delete;
    GameState(const GameState& orig) = delete;
    GameState(GameData* gData);
    
    //Main Menu Functions
    virtual void ShowCredits() = 0;
    virtual void ShowHelpSection() = 0;
    virtual void ShowMenu() = 0;
    
    virtual ~GameState();
};

#endif