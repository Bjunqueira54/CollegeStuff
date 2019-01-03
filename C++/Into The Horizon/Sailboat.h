#ifndef SAILBOAT_H
#define SAILBOAT_H

#include "Ship.h"

class Sailboat: public Ship
{
    
public:
    
    Sailboat(Player* o, int id, int y, int x, bool sih);
    
    const int getType() const { return 1; }
	const string getShipInfo() const;
    
    virtual ~Sailboat();
};

#endif