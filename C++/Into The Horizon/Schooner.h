#ifndef SCHOONER_H
#define SCHOONER_H

#include "Ship.h"

class Schooner: public Ship
{
    
public:

    Schooner(Player* o, int id, int y, int x);
    
    const int getType() const { return 3; }
	const string getShipInfo() const;
    
    
    virtual ~Schooner();
};

#endif