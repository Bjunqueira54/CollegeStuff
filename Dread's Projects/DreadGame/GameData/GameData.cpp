#include "GameData.h"

GameData::GameData()
{
    player = nullptr;
    NPC = new NPC();
}

void GameData::CreatePlayer(string name)
{
    player = new Player(name);
}

const string GameData::getPlayerName()
{
    return player->getName();
}

int GameData::getPlayerHP()
{
    return player->getHP();
}

int GameData::getPlayerDamage()
{
    return player->getDamage();
}

int GameData::getMonsterHP()
{
    return monster->getHP();
}

int GameData::getMonsterDamage()
{
    return monster->getDamage();
}

GameData::~GameData() {}