#ifndef FRIGATE_H
#define FRIGATE_H

#include "Ship.h"

class Frigate: public Ship
{
    
public:
    
    /*Frigate();
    Frigate(const Frigate& orig);*/
    Frigate(Player* o, int id, int y, int x, bool sih);
    
    const int getType() const { return 4; }
	const string getShipInfo() const;
    
    virtual ~Frigate();
};

#endif