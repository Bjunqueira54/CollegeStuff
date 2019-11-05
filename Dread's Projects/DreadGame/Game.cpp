#include "Game.h"

Game::Game(string name)
{
    gData = new GameData(name);
}

Game::~Game()
{
    delete gData;
    delete gState;
}