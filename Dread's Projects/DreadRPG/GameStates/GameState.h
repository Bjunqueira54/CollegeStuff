#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../includes.h"

class GameState
{
    
public:
    GameState();
    GameState(const GameState& orig);
    
    void HelloAbstract() = 0;
    
    virtual ~GameState();
};

#endif