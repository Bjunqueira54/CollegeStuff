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
    
    const string getName() { return this->pName; }
    int getDamage();
    const int getHP() { return this->HP; }
    void setHP(int value) {this->HP -= value; }
    
    virtual ~Player();
};

#endif