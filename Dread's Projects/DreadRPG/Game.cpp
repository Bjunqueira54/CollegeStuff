#include "Game.h"

Game::Game(): gData(new GameData()), gState(new MainMenuState()) {}

void Game::Start()
{
    Interface::WelcomeScreen();
    MainGameLoop();
}

void Game::MainGameLoop()
{
    if(instanceof<MainMenuState>(gState))
        cout << "This Works" << endl;
}

Game::~Game() {}