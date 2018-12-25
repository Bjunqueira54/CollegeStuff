#ifndef GAME_H
#define GAME_H

#include "headers.h"
#include "Player.h"
#include "Settings.h"
#include "Map.h"

class Game
{
    static Player* player;
    static Player* pirate;
    static Settings* settings;
    static Map* map;
    static int turn;
    
public:
    
    Game();
    Game(const Game& orig);
    Game(string n, int m);
    
    
    
    virtual ~Game();
};

#endif