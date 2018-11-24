#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"
#include "Ship.h"

class Player
{
    const string *name;
    int money;
    vector<Ship*> fleet;
    
public:
    
    Player();
    Player(string n);
    Player(const Player& orig);
    
    Player& operator=(const Player& orig);
    
    //Get
    
    const string GetName() const {return *name;}
    int GetMoney() const {return money;}
    vector<Ship*> GetFleet() const {return fleet;}

    //Set
    
    void SetMoney(int money)
    {this->money = money;}
    
    void newShip(char t);
    
    virtual ~Player();
};

#endif