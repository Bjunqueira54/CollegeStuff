#ifndef NPC_H
#define NPC_H

#include "includes.h"

class NPC
{
    int hp;
    int damage;
    
    bool isStunned;
    
    int StunRound;
    
public:
    
    NPC();
    NPC(const NPC& orig) = delete;
    
    const int getDamage() { return DamageRoll(); }
    const int getHP() { return hp; }
    const bool getStunState() { return isStunned; }
    
    void DealDamage();
    void setStun();
    void NextRound();
    
    virtual ~NPC();
    
private:
    
    const int DamageRoll();
};

#endif