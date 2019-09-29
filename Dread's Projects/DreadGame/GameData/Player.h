#ifndef PLAYER_H
#define PLAYER_H

#include "../includes.h"

class Player
{
    const string pName;
    int HP, MP;
    
    int STR, DEX, INT;
    
public:

    Player() = delete;
    Player(string name);
    
    int getHP() { return HP; }
    int getDamage();
    int getSpecial();
    const string getName() { return pName; }

    void TakeDamage(int damage);
    void Heal(int health);
    
    virtual ~Player();
};

#endif