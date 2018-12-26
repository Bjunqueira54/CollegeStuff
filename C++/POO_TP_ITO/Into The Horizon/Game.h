#ifndef GAME_H
#define GAME_H

#include "headers.h"
#include "Player.h"
#include "Settings.h"
#include "Map.h"

class Game
{
    const string playername;
    static Player* player;
    static Player* pirate;
    static Settings* settings;
    static Map* map;
    static int turn;
    int phase = 0;
    
public:
    
    Game();
    Game(const Game& orig);
    Game(string n);
    
    void configPhase();
    void startGame();
    
    virtual ~Game();
};

#endif