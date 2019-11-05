#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../includes.h"
#include "../GameData.h"

class GameState
{
    const GameData* gData;

public:
    
    GameState() = delete;
    GameState(const GameState& orig) = delete;
    GameState(GameData*);
    
    const GameData* getGameData() { return gData; }
    
    virtual ~GameState();
};

#endif