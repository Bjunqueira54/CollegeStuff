#include "DreadRPG.h"

DreadRPG::DreadRPG()
{
    gState = nullptr;
    isExiting = false;
}

DreadRPG::DreadRPG(const DreadRPG& orig) {}

void DreadRPG::Start()
{
    /*
    if(gState == nullptr)
        gState = new MainMenuState();
    */
    
    do
    {
        
    }
    while(!isExiting);
}

DreadRPG::~DreadRPG() {}