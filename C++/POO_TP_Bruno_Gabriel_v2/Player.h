#ifndef PLAYER_H
#define PLAYER_H

#include "headers.h"
#include "Ship.h"

class Harbor;

class Player
{
    const string *name;
    int money;
    vector<Ship*> fleet;
    Harbor *MainHarbor;
    
public:
    
    Player();
    Player(string n);
    Player(const Player& orig);
    
    Player& operator=(const Player& orig);
    
    //Get
    
    const string GetName() const {return *name;}
    int GetMoney() const {return money;}
    vector<Ship*> GetFleet() const {return fleet;}
    const string getMainHarborCoord() const;

    //Set
    
    void SetMoney(int money) {this->money = money;}
    void addMoney(int n) {money += n;}
    void SetMainHarbor(Harbor* main) {MainHarbor = main;}
    
    void newShip(char t);
    
    virtual ~Player();
};

#endif