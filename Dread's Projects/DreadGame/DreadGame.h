#ifndef DREADGAME_H
#define DREADGAME_H

#include "includes.h"
#include "GameData/GameData.h"
#include "GameStates/GameState.h"
#include "Interface.h"

class DreadGame
{
    GameData *gData;
    GameState *gState;
    
    bool isExiting;
    
public:

    DreadGame();
    
    void Init();
    
    virtual ~DreadGame();
    
private:
    
    void MainGameLoop();
    
    void MainMenu();
    
    void StartGame();
    
    template<typename Base, typename T>
    inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
};

#endif