#include "Game.h"

Game::Game()
{
    interface = new Interface();
    monster = new NPC();
}

void Game::start()
{
    getchar();
    DrawMainMenu();
    
    int opt = 0;
    
    while(opt != 1 && opt != 2)
        opt = interface->getOpt();
}

Game::~Game()
{
    delete interface;
    delete player;
    delete monster;
}