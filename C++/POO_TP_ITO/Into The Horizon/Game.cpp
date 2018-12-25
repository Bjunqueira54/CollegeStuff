#include "Game.h"

Game::Game() {}

Game::Game(const Game& orig) {}

Game::Game(string n, int m)
{
    player = new Player(n, m);
    pirate = new Player("Pirates", 0);
}

Game::~Game()
{
    delete player;
    delete pirate;
}