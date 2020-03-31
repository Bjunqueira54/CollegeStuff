#ifndef GAME_H
#define GAME_H

#include "includes.h"

#include "Interface.h"
#include "GameData.h"
#include "GameState.h"

class Game
{
    Interface* const interface;
    GameData* const gData;
    GameState* const gState;
    
public:
    Game();
    Game(const Game& orig);
    
    void Start();
    
    virtual ~Game();
    
private:
    void MainGameLoop();
};

#endif