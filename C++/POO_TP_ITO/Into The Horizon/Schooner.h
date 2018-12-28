#ifndef SCHOONER_H
#define SCHOONER_H

#include "Ship.h"

class Schooner: public Ship
{
    
public:

    Schooner(Player* o, int id, int x, int y);
    
    const int getType() const { return 3; }
    
    
    virtual ~Schooner();
};

#endif