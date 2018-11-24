#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"

class Player
{
    const string *name;
    int money;
    
public:
    
    Player();
    Player(string n);
    Player(const Player& orig);
    
    Player& operator=(const Player& orig);
    
    const string GetName() const
    {return *name;}
    
    int GetMoney() const
    {return money;}

    void SetMoney(int money)
    {this->money = money;}

    
    virtual ~Player();
};

#endif