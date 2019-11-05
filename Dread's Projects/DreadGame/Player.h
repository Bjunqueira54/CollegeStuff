#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"

class Player
{
    const string Name;
    
    int Health;
    int Mana;
    
public:
    
    Player() = delete;
    Player(const Player& orig) = delete;
    Player(string);
    
    virtual ~Player();
};

#endif