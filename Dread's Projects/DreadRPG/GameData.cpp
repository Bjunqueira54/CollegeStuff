#include "GameData.h"
#include "Player.h"

GameData::GameData() {}

GameData::GameData(const GameData& orig) {}

GameData::GameData(string name)
{
    player = new Player(name);
    monster = new NPC();
}

GameData::~GameData() {}