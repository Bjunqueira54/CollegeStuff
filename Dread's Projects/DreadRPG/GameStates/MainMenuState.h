#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../includes.h"
#include "GameState.h"

class MainMenuState: public GameState
{
public:

    MainMenuState();
    MainMenuState(const MainMenuState& orig);
    
    virtual void PrintMenu() override { Interface::MainMenu(); }
    
    void Attack() override {};
    void Block() override {};
    void Cast() override {};
    void Heal() override {};
    void Run() override {};
    void Load() override {};
    void Save() override {};
    void Talk() override {};
    void Walk() override {};

    virtual ~MainMenuState();
};

#endif