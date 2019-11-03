#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"

class Player
{
    const string name;
    int HP;
    
public:
    
    Player() = delete;
    Player(const Player& orig) = delete;
    Player(string name, int hp);
    
    const int getHP() { return HP; }
    const string getName() { return name; }
    
    void takeDamage(int);
    
    virtual ~Player();
};

#endif