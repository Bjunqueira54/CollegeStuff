#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "GameState.h"
#include "../GameData/GameData.h"

class BattleState: public GameState
{
    
public:
    
    BattleState() = delete;
    BattleState(const BattleState& orig) = delete;
    BattleState(GameData data);
    
    virtual ~BattleState();

private:

};

#endif