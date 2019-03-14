#include "Game.h"

Game::Game()
{
    interface = new Interface();
    monster = new NPC();
}

void Game::start()
{
    //interface.introduction();
}

Game::~Game()
{
    delete interface;
    delete player;
    delete monster;
}