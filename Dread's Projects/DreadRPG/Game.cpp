#include "Game.h"
#include "GameStates/MainGameState.h"

Game::Game(): gData(new GameData()), gState(new MainMenuState()) {}

void Game::Start()
{
    Interface::WelcomeScreen();
    Interface::ClearScreen();
    MainGameLoop();
}

void Game::MainGameLoop()
{
    if(instanceof<MainMenuState>(gState))
    {
        char opt;
        gState->PrintMenu();
        
        opt = Interface::getChar();
        
        switch(opt)
        {
            case '1':
                gState = new MainGameState(Interface::getPlayerName());
                break;
            case '2':
                gState->Tutorial();
                break;
            case '0':
                break;
            default: break;
        }
    }
    
    //for now this is just the main battle loop
    if(instanceof<MainGameState>(gState))
    {
        gState->PrintMenu();
    }
}

Game::~Game() {}