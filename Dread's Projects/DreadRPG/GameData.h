#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "includes.h"
#include "Player.h"
#include "NPC.h"

class GameData
{
    Player* player;
    NPC* monster;
public:

    GameData();
    GameData(const GameData& orig);
    GameData(string name);

    virtual ~GameData();
};

#endif