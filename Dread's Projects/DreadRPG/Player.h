#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"

class Player
{
    const string pName;
    int STR, DEX, INT;
    int HP, MP;
    
    bool isBlocking;
    
public:

    Player() = delete;
    Player(const Player& orig);
    Player(string name);
    
    int getAttack();
    void Block();
    int Heal();
    int getSpecial();

    virtual ~Player();
};

#endif