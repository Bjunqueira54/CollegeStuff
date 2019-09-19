#include "Game.h"

Game::Game(): interface(new Interface()), gData(new GameData()), gState(new GameState()) {}

Game::Game(const Game& orig): interface(orig.interface), gData(orig.gData), gState(orig.gState) {}

void Game::Start()
{
    MainGameLoop();
}

void Game::MainGameLoop()
{
    interface->WelcomeScreen();
    interface->ClearScreen();
    
    int option = 0;
    
    do
    {
        
    }
    while(option != 0);
}

Game::~Game()
{
    delete interface;
    delete gData;
    delete gState;
}