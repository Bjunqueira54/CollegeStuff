#include "DreadGame.h"
#include "GameStates/BattleState.h"

DreadGame::DreadGame()
{
    gData = nullptr;
    gState = nullptr;
    
    isExiting = false;
}

void DreadGame::Init()
{
    Interface::WelcomeScreen();
    gState = new MainMenuState();
    MainGameLoop();
}

void DreadGame::MainGameLoop()
{
    if(instanceof<MainMenuState>(gState))
        MainMenu();
    /*else if(instanceof<BattleState>(gState))
        BattleMenu();*/
}

void DreadGame::MainMenu()
{
    char opt;
    
    do
    {
        Interface::PrintMainMenu();

        opt = Interface::getChar();

        switch(opt)
        {
            case '1':
                StartGame();
                break;
            case '2':
                Interface::ShowCredits();
                break;
            case '0':
                isExiting = true;
                break;
            default:
                break;
        }
    }
    while(!isExiting);
}

void DreadGame::StartGame()
{
    gData = new GameData();
    Interface::StartGame();
    gData->CreatePlayer(Interface::getString());
    gState = new BattleState(gData);
}

DreadGame::~DreadGame()
{
    delete gData;
    delete gState;
}