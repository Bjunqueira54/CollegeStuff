#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
	Player *player;

	vector<Enemy*> enemies;

public:

	Game();
	~Game();
};

#endif