#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "../includes.h"
#include "GameState.h"

class BattleState: public GameState
{
public:
    BattleState() = delete;
    BattleState(const BattleState& orig) = delete;
    BattleState(GameData*);
    
    const virtual string getStateName() { return "BattleState"; }
    
    virtual ~BattleState();
};

#endif