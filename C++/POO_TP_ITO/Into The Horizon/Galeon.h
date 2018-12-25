#ifndef GALEON_H
#define GALEON_H

#include "Ship.h"

class Galeon: public Ship
{
    
public:
    
    Galeon();
    Galeon(const Galeon& orig);
    virtual ~Galeon();
};

#endif