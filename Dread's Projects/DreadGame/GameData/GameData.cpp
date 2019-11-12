#include "GameData.h"

GameData::GameData(string name)
{
    player = new Player(name);
}

GameData::~GameData()
{
    delete player;
}