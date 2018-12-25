#ifndef FRIGATE_H
#define FRIGATE_H

#include "Ship.h"

class Frigate: public Ship
{
    
public:
    
    Frigate();
    Frigate(const Frigate& orig);
    virtual ~Frigate();
};

#endif