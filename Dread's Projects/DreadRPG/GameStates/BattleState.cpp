#include "BattleState.h"

BattleState::BattleState(GameData* gData): GameState(gData) {}

void BattleState::Attack()
{
    int pDmg, pHP, mDmg, mHP;
    pDmg = gData->getPlayerDamage();
    pHP = gData->getPlayerHP();
    
    mDmg = gData->getMonsterDamage();
    mHP = gData->getMonsterHP();
    
    cout << gData->getPlayerName() << " has " << pHP << " HP and the monster has " << mHP << " HP" << endl;
    cout << "The monster takes" << pDmg << " damage and " << gData->getPlayerName() << " takes " << mDmg << " damage." << endl;
    
    gData->setMonsterHP(pDmg);
    gData->setPlayerHP(mDmg);
}

BattleState::~BattleState() {}