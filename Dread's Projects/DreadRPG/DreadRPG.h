#ifndef DREADRPG_H
#define DREADRPG_H

#include "includes.h"
#include "Interface.h"
#include "GameStates/States.h"

//for now include this, remove later when States.h is
//populated
#include "GameStates/GameState.h"

class DreadRPG
{
    GameState* gState;
    
    bool isExiting;
    
public:
    DreadRPG();
    DreadRPG(const DreadRPG& orig);
    
    void Start();
    
    virtual ~DreadRPG();

private:
    
template<typename Base, typename T>
    inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base*>(ptr) != nullptr;
    }
};

#endif