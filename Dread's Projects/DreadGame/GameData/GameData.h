#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "../includes.h"
#include "Player.h"

class GameData
{
    Player* player;
    
public:
    
    GameData() = delete;
    GameData(const GameData& orig) = delete;
    GameData(string name);
    
    
    virtual ~GameData();
};

#endif