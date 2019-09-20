#ifndef NPC_H
#define NPC_H

#include "../includes.h"

class NPC
{
    int HP;
    
public:
    NPC();
    NPC(const NPC& orig) = delete;
    
    int getHP() { return HP; }
    int getDmg();
    void setHP(int dmg) { HP -= dmg; }
    
    virtual ~NPC();
};

#endif