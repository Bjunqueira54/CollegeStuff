#ifndef NPC_H
#define NPC_H

#include "../includes.h"

class NPC
{
    int HP;
    
public:

    NPC();
    NPC(const NPC& orig);

    int getHP() { return HP; }
    int getDamage();
    void TakeDamage(int damage);
    
    virtual ~NPC();
};

#endif