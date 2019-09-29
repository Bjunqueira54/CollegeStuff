#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "../includes.h"
#include "Player.h"
#include "NPC.h"

class GameData
{
    Player *player;
    NPC *monster;
    
public:

    GameData();

    void CreatePlayer(string name);
    
    const string getPlayerName();
    int getPlayerHP();
    int getPlayerDamage();
    
    int getMonsterHP();
    int getMonsterDamage();
    
    virtual ~GameData();
};

#endif