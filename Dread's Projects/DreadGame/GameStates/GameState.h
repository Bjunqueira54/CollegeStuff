#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../includes.h"
#include "../GameData/GameData.h"

class GameState
{
    const GameData* gData;

public:
    
    GameState() = delete;
    GameState(const GameState& orig) = delete;
    GameState(GameData*);
    
    const virtual string getStateName() = 0;
    
    virtual ~GameState();
    
protected:
    
    const GameData* getGameData() { return gData; }
};

#endif