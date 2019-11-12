#include "Game.h"

Game::Game(string name)
{
    gData = new GameData(name);
    gState = new MainMenuState(gData);
}

void Game::UserInput(char)
{
    
}

Game::~Game()
{
    delete gData;
    delete gState;
}