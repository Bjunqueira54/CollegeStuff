#include "Game.h"

int Game::turn;
Player* Game::pirate;
Player* Game::player;

Game::Game() {}

Game::Game(const Game& orig) {}

Game::Game(string n): playername(n)
{
    turn = 0;
}

void Game::startGame()
{
    player = new Player(playername, settings->GetStartmoney());
    pirate = new Player("Pirates", 0);
}

void Game::configPhase(string filename)
{
    if(phase != 0)
	return;
    
    settings = new Settings(filename);
    map = new Map(settings.getMap());
    phase = 1;
}

Game::~Game()
{
    delete player;
    delete pirate;
    delete settings;
    delete map;
}