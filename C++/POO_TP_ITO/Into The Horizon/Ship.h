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
	bool Auto = false;
	bool Stopped = true;
	bool DestHarbor = false;
    
    Player* owner;
    
public:
    
    //No objects of ship please :)
    Ship() = delete;
    
    //Derivative Constructor
    Ship(Player* o, int id, int x, int y, int mm, int mc, int mw, int ml);
    
    int setDestination(int dy, int dx, bool idh);
	void move(int newy, int newx);
    
    const int getID() const { return id; }
    const int getCargo() const { return cargo; }
    const int getCrew() const { return crew; }
    const int getFish() const { return fish; }
    const int getMaxmoves() const { return maxmoves; }
    const int getMoves() const { return moves; }
    const int getWater() const { return water; }
    const string getCoord() const;
	const string getDestCoord() const;
    const bool isInHarbor() const { return inHarbor; }
	bool isAuto() const { return Auto; }
	bool isDestHarbor() const { return DestHarbor; }
	bool isStopped() const { return Stopped; }
    
    virtual const int getType() const = 0;
    
    const Player& getOwner() { return *owner; }
    
    virtual ~Ship();
    
private:
    
    void whatdir();
};

#endif