#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Ship.h"

class Sailboat: public Ship
{
    
public:
    
    Sailboat(Player* o, int id, int x, int y);
    
    const int getType() const { return 1; }
    
    virtual ~Sailboat();
};

#endif