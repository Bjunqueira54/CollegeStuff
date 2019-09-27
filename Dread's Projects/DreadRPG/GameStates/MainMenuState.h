#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState: public GameState
{
public:
    MainMenuState() = delete;
    MainMenuState(const MainMenuState& orig) = delete;
    MainMenuState(GameData* gData);
    
    void ShowCredits() override;
    void ShowHelpSection() override;
    void ShowMenu() override;
    void Attack() override {};

    virtual ~MainMenuState();

private:

};

#endif