#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "Interface.h"
#include "Player.h"
#include "NPC.h"

class Game
{
    int rounds;
    Interface* interface;
    Player player;
    NPC monster;
    
public:
    
    Game();
    Game(const Game& orig) = delete;
    
    void start();
    
    virtual ~Game();
    
private:
    
    void victory();
    void defeat();
};

#endif