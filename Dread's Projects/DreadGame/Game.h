#ifndef GAME_H
#define GAME_H

#include "includes.h"
#include "GameStates/stateinclude.h"
#include "GameData/GameData.h"

class Game
{
    GameData* gData;
    GameState* gState;
    
public:
    
    Game() = delete;
    Game(const Game& orig) = delete;
    Game(string name);
    
    /////////////
    ///Getters///
    /////////////
    
    string getGameState() { return gState->getStateName(); }
    
    void UserInput(char);
    
    virtual ~Game();
    
private:
    
    template<typename Base, typename T> inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
};

#endif