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
    void MainMenu();
    void StartGame();
    
    virtual ~DreadGame();
    
private:
    
    void Attack();
    void SpecialAttack();
    void Heal();
    void Block();
    void RunAway();
    
    template<typename Base, typename T>
    inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
};

#endif