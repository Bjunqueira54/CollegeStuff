#include "Game.h"

int Game::turn;
Player* Game::pirate;
Player* Game::player;

Game::Game() {}

Game::Game(const Game& orig) {}

Game::Game(string n, int m)
{
    player = new Player(n, m);
    pirate = new Player("Pirates", 0);
    turn = 0;
}

Game::~Game()
{
    delete player;
    delete pirate;
}