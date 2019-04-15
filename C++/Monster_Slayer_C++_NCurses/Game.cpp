#include "Game.h"
#include "Player.h"

Game::Game()
{
    interface = new Interface();
}

void Game::start()
{
    string PlayerName;
    
    getchar();
    DrawMainMenu();
    
    int opt = 0;
    
    while(opt != 1 && opt != 2)
    {
        opt = interface->getOpt();
        
        switch(opt)
        {
            case '1':
                PlayerName = interface->getName(stdscr);
                break;
            case '2':
                break;
            default:
                opt = 0;
        }
    }
}

Game::~Game()
{
    delete interface;
    delete player;
    delete monster;
}