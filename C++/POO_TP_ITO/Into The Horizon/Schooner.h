#ifndef SCHOONER_H
#define SCHOONER_H

#include "Ship.h"

class Schooner: public Ship
{
    
public:
    
    Schooner();
    Schooner(const Schooner& orig);
    Schooner(int x, int y);
    
    
    virtual ~Schooner();
};

#endif