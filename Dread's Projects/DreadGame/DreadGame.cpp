#include "DreadGame.h"

DreadGame::DreadGame()
{
    gData = nullptr;
    gState = nullptr;
    
    isExiting = false;
}

void DreadGame::Init()
{
    Interface::WelcomeScreen();
    MainMenu();
}

void DreadGame::MainMenu()
{
    char opt;
    
    do
    {
        Interface::PrintMainMenu();

        opt = Interface::getChar();

        switch(opt)
        {
            case '1':
                StartGame();
                break;
            case '2':
                Interface::ShowCredits();
                break;
            case '0':
                isExiting = true;
                break;
            default:
                break;
        }
    }
    while(!isExiting);
}

void DreadGame::StartGame()
{
    char opt;
    gData = new GameData();
    gData->CreatePlayer(Interface::getString());
    
    do
    {
        Interface::PrintBattleMenu(gData.getPlayerName(), gData->getPlayerHP(), gData->getMonsterHP());
        opt = Interface::getChar();
        
        switch(opt)
        {
            case '1':
                Attack();
                break;
            case '2':
                SpecialAttack();
                break;
            case '3':
                Heal();
                break;
            case '4':
                Block();
                break;
            case '0':
                RunAway();
                break;
            default:
                break;
        }
    }
    while(gData->getPlayerHP() > 0 && gData->getMonsterHP() > 0);
    
    if(gData->getPlayerHP() <= 0)
        Interface::Defeat();
    else if(gData->getMonsterHP() <= 0)
        Interface::Victory();
}

void DreadGame::Attack()
{
    int player_Damage, monster_Damage;
    int player_HP, monster_HP;
    
    player_HP = gData->getPlayerHP();
    monster_HP = gData->getMonsterHP();
    
    player_Damage = gData->getPlayerDamage();
    monster_Damage = gData->getMonsterDamage();
}


DreadGame::~DreadGame()
{
    delete gData;
    delete gState;
}