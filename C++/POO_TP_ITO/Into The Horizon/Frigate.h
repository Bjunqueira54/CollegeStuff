#ifndef FRIGATE_H
#define FRIGATE_H

#include "Ship.h"

class Frigate: public Ship
{
    
public:
    
    Frigate();
    Frigate(const Frigate& orig);
    Frigate(int x, int y);
    
    
    
    virtual ~Frigate();
};

#endif