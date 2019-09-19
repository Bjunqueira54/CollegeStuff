#ifndef MAINGAMESTATE_H
#define MAINGAMESTATE_H

#include "../includes.h"
#include "GameState.h"
#include "../GameData.h"

class MainGameState: public GameState
{
    GameData *gData;
public:

    MainGameState() = delete;
    MainGameState(const GameData &gData) = delete;
    MainGameState(string name);
    
    void Attack() override;
    void Block() override;
    void Cast() override;
    void Heal() override;
    void Load() override;
    void PrintMenu() override { Interface::BattleMenu(); };
    void Run() override;
    void Save() override;
    void Talk() override;
    void Tutorial() override;
    void Walk() override;

    virtual ~MainGameState();
};

#endif