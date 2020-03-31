#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"
#include "Class.h"

class Player
{
    const string pName;
    int STR, DEX, INT;
    int HP, MP;
    
    //const Class* const pClass;
    
public:
    Player() = delete;
    Player(string name);
    Player(const Player& orig);
    virtual ~Player();

private:

};

#endif