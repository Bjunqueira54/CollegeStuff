#include "GameData.h"

GameData::GameData(string name)
{
    player = new Player(name);
    monster = new NPC();
}

GameData::~GameData() {}