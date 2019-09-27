#ifndef DREADRPG_H
#define DREADRPG_H

#include "includes.h"
#include "Interface.h"
#include "GameStates/States.h"
#include "GameData/GameData.h"

class DreadRPG
{
    GameState* gState;
    GameData* gData;
    
    bool isExiting;
    
public:
    DreadRPG();
    DreadRPG(const DreadRPG& orig);
    
    void Init();
    void StartGame();
    void EndGame();
    
    void MainMenuLoop();
    void MainBattleLoop();
    
    virtual ~DreadRPG();

private:
    
    char getOpt();
    string getString();
    int CharToInt(char c);
    
    void MainMenuProc(char opt);
    void BattleMenuProc(char opt);
    
    void ToggleIsExiting() { isExiting = !isExiting; }
    
template<typename Base, typename T>
    inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
};

#endif