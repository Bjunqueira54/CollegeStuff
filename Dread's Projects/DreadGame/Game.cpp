#include "Game.h"

Game::Game(string name)
{
    gData = new GameData(name);
    gState = new MainMenuState(gData);
}

void Game::UserInput(char option)
{
    if(instanceof<MainMenuState>(gState))
        MainMenuInput(option);
    else if(instanceof<BattleState>(gState))
        BattleStateInput(option);
}

void Game::MainMenuInput(char option)
{
    switch(option)
    {
        case '1':
            gState = new BattleState(gData);
            break;
        case '2':
            break;
        case '3':
            break;
        case '0':
            break;
        default:
            break;
    }
}

void Game::BattleStateInput(char option)
{
    switch(option)
    {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '0':
            break;
        default:
            break;
    }
}

Game::~Game()
{
    delete gData;
    delete gState;
}