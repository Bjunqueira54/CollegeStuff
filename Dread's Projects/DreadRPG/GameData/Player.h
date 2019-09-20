#ifndef PLAYER_H
#define PLAYER_H

#include "../includes.h"

class Player
{
    const string pName;
    
    int STR, DEX, INT;
    int HP, MP;
    
    bool isBlocking;
    bool isHealing;
    
public:
    Player() = delete;
    Player(const Player& orig) = delete;
    Player(string name);
    
    virtual ~Player();
};

#endif