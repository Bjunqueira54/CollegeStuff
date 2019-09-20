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
    }
    while(!isExiting);
}

void DreadRPG::MainMenuLoop()
{
    char opt;
    
    do
    {
        gState->ShowMenu();
        opt = getOpt();
        
        MainMenuProc(opt);
    }
    while(opt != '0');
}

char DreadRPG::getOpt()
{
    Interface::getChar();
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
            //StartGame();
            break;
        case '2':
            gState->ShowHelpSection();
            break;
        case '3':
            gState->ShowCredits();
            break;
        case '0':
            ToggleIsExiting();
            break;
        default:
            break;
    }
}

DreadRPG::~DreadRPG() {}