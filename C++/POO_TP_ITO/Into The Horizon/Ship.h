#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

class Player;

class Ship
{
    int x, y;
    const int id, maxmoves, maxcrew, maxwater, maxload;
    int moves, crew, water, cargo, fish;
    
    Player* owner;
    
public:
    
    Ship() = delete;
    /*Ship(const Ship& orig);*/
    
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
    
    const Player& getOwner() { return *owner; }
    
    virtual ~Ship();
};

#endif