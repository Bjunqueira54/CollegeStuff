#ifndef SCHOONER_H
#define SCHOONER_H

#include "Ship.h"

class Schooner: public Ship
{
    
public:
    
    Schooner();
    Schooner(const Schooner& orig);
    virtual ~Schooner();
};

#endif