#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

class Ship
{
    int x, y;
    const int maxmoves, maxcrew, maxwater, maxload;
    int moves, crew, water, cargo, fish;
    
    Player* owner;
    
public:
    
    Ship();
    Ship(const Ship& orig);
    
    //Derivative Constructor
    Ship(int x, int y, int mm, int mc, int mw, int ml);
    
    void move(string dir);
    void moveto(int x, int y);
    
    virtual ~Ship();
};

#endif