#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "../includes.h"
#include "Player.h"
#include "NPC.h"

class GameData
{
    Player* player;
    NPC* monster;
    
public:
    GameData() = delete;
    GameData(const GameData& orig) = delete;
    GameData(string name);
    
    const string getPlayerName() { return player->getName(); }
    int getPlayerDamage() { return player->getDamage(); }
    int getPlayerHP() { return player->getHP(); }
    void setPlayerHP(int dmg) { player->setHP(dmg); }
    
    int getMonsterDamage() {return monster->getDmg(); }
    int getMonsterHP() { return monster->getHP(); }
    void setMonsterHP(int dmg) { monster->setHP(dmg); }
    
    
    virtual ~GameData();

private:

};

#endif