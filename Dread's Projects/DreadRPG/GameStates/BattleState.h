#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "GameState.h"

class BattleState: public GameState
{
    GameData* gData;
public:
    BattleState() = delete;
    BattleState(const BattleState& orig) = delete;
    BattleState(GameData* gData);
    
    void ShowCredits() override {}
    void ShowHelpSection() override {}
    void ShowMenu() override { Interface::PrintBattleMenu(); }
    
    void Attack() override;
    
    virtual ~BattleState();
};

#endif