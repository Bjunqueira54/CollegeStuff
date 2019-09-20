#include "DreadRPG.h"

DreadRPG::DreadRPG()
{
    gState = nullptr;
    gData = nullptr;
    isExiting = false;
}

DreadRPG::DreadRPG(const DreadRPG& orig) {}

void DreadRPG::Init()
{
    if(gState == nullptr)
        gState = new MainMenuState(gData);
    
    do
    {
        if(instanceof<MainMenuState>(gState))
            MainMenuLoop();
        if(instanceof<BattleState>(gState))
            MainBattleLoop();
    }
    while(!isExiting);
}

void DreadRPG::StartGame()
{
    Interface::GetNameScreen();
    string name = getString();
    gData = new GameData(name);
    gState = new BattleState(gData);
}

void DreadRPG::MainMenuLoop()
{
    char opt;

    gState->ShowMenu();
    opt = getOpt();

    MainMenuProc(opt);
}

void DreadRPG::MainBattleLoop()
{
    char opt;
    
    gState->ShowMenu();
    opt = getOpt();
    
    BattleMenuProc(opt);
}

char DreadRPG::getOpt()
{
    Interface::getChar();
}

string DreadRPG::getString()
{
    return Interface::getString();
}

int DreadRPG::CharToInt(char c)
{
    int conv;
    conv = c;
    return conv;
}

void DreadRPG::MainMenuProc(char opt)
{
    switch(opt)
    {
        case '1':
            StartGame();
            break;
        case '2':
            gState->ShowHelpSection();
            getchar();
            break;
        case '3':
            gState->ShowCredits();
            getchar();
            break;
        case '0':
            ToggleIsExiting();
            break;
        default:
            break;
    }
}

void DreadRPG::BattleMenuProc(char opt)
{
    switch(opt)
    {
        case '1':
            //Attack
            break;
        case '2':
            //Special Attack
            break;
        case '3':
            //Defend
            break;
        case '4':
            //Heal
            break;
        case '0':
            //Run
            break;
        default:
            break;
    }
}

DreadRPG::~DreadRPG() {}