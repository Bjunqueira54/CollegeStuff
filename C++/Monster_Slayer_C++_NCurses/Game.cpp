#include "Game.h"
#include "Player.h"

Game::Game()
{
    interface = new Interface();
    monster = new NPC();
    player = new Player("GothicDreadTest");
}

void Game::start()
{
    getchar();
    DrawMainMenu();
    getchar();
    interface->DrawRenderModel(stdscr, player->getRenderCoord());
    
    int opt = 0;
    
    /*while(opt != 1 && opt != 2)
        opt = interface->getOpt();*/
}

Game::~Game()
{
    delete interface;
    delete player;
    delete monster;
}