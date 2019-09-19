#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "GameData.h"
#include "GameStates/States.h"

class Game
{
    const GameData * gData;
    const GameState * gState;
    
public:
    
    Game();
    
    void Start();
    void MainGameLoop();
    
    virtual ~Game();
};

#endif