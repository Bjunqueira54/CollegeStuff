#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

class Player;

class Ship
{
    int x, y, id;
    int destx, desty;
    const int maxmoves, maxcrew, maxwater, maxload;
    int moves, crew, water, cargo, fish;
    bool inHarbor = true;
    
    Player* owner;
    
public:
    
    //No objects of ship please :)
    Ship() = delete;
    
    //Derivative Constructor
    Ship(Player* o, int id, int x, int y, int mm, int mc, int mw, int ml);
    
    void move(string dir);
    void moveto(int x, int y);
    
    const int getID() const { return id; }
    const int getCargo() const { return cargo; }
    const int getCrew() const { return crew; }
    const int getFish() const { return fish; }
    const int getMaxmoves() const { return maxmoves; }
    const int getMoves() const { return moves; }
    const int getWater() const { return water; }
    const string getCoord() const;
    const bool isInHarbor() const { return inHarbor; }
    
    virtual const int getType() const = 0;
    
    const Player& getOwner() { return *owner; }
    
    virtual ~Ship();
    
private:
    
    int whatdir(char d);
};

#endif