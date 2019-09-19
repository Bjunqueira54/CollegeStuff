#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../includes.h"
#include "../Interface.h"

class GameState
{
public:

    GameState() {};
    GameState(const GameState& orig) {};
    
    //Menu Related Functions
    virtual void PrintMenu() = 0;
    
    //World Related Functions
    virtual void Walk() = 0;
    virtual void Talk() = 0;
    virtual void Save() = 0;
    virtual void Load() = 0;
    
    //Combat Related Functions
    virtual void Attack() = 0;
    virtual void Heal() = 0;
    virtual void Block() = 0;
    virtual void Run() = 0;
    virtual void Cast() = 0;

    virtual ~GameState() {};
};

#endif