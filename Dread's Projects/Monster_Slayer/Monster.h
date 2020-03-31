#ifndef MONSTER_H
#define MONSTER_H

#include "includes.h"

class Monster
{
    int HP;
    
public:
    
    Monster() = delete;
    Monster(const Monster& orig) = delete;
    Monster(int h);
    
    const int getHP() { return HP; }
    
    void takeDamage(int);
    
    virtual ~Monster();
};

#endif